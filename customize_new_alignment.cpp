#include <iostream>
#include <memory>
#include <assert.h>
#define DEFAULT_ALIGNMENT (128)
//here is a code inspired by eigen
//I use the Args... template to support multi variables constructor, 
//Args make things elegent, but rely on c++11  

inline void* handmade_aligned_malloc(std::size_t size, std::size_t alignment = DEFAULT_ALIGNMENT)
{
  assert(alignment >= sizeof(void*) && (alignment & (alignment-1)) == 0 && "Alignment must be at least sizeof(void*) and a power of 2");
  void *original = malloc(size+alignment);
  
  if (original == 0) return 0;
  void *aligned = reinterpret_cast<void*>((reinterpret_cast<std::size_t>(original) & ~(std::size_t(alignment-1))) + alignment);
  *(reinterpret_cast<void**>(aligned) - 1) = original;
  return aligned;
}

/** \internal Frees memory allocated with handmade_aligned_malloc */
inline void handmade_aligned_free(void *ptr)
{
  if (ptr) {
    std::free(*(reinterpret_cast<void**>(ptr) - 1));
  }
}

/** \internal Frees memory allocated with aligned_malloc. */
inline void aligned_free(void *ptr)
{
  std::free(ptr);
}

/** \internal Destructs the elements of an array.
  * The \a size parameters tells on how many objects to call the destructor of T.
  */
template<typename T> inline void destruct_elements_of_array(T *ptr, std::size_t size)
{
  // always destruct an array starting from the end.
  if(ptr)
    while(size) ptr[--size].~T();
}

template<typename T, typename... Args>  
inline T* construct_elements_of_array(int size, T *ptr, Args... args)
{
  std::size_t i;
  try
  {
      for (i = 0; i < size; ++i) ::new (ptr + i) T(args...);
      return ptr;
  }
  catch(...)
  {
    destruct_elements_of_array(ptr, i);
  }
  return NULL;
}

/** \internal Deletes objects constructed with aligned_new
  * The \a size parameters tells on how many objects to call the destructor of T.
  */
template<typename T> inline void aligned_delete(T *ptr, std::size_t size)
{
  destruct_elements_of_array<T>(ptr, size);
  handmade_aligned_free(ptr);
}

template<typename T, typename... Args>
inline T* aligned_new(std::size_t size, Args... args)
{
  //check_size_for_overflow<T>(size);
  T *result = static_cast<T*>(handmade_aligned_malloc(sizeof(T)*size));
  try
  {
    return construct_elements_of_array(size, result, args...);
  }
  catch(...)
  {
    handmade_aligned_free(result);
  }
  return result;
}

class A
{
  public:
  A(){ std::cout << "A constructer" << std::endl; }
  A(int val){ std::cout << "A(int) constructer: val=" << val << std::endl; }
  ~A(){std::cout << "A deconstruct" << std::endl;}
  int m_data[10];
};

int main()
{
  auto ptr = aligned_new<A>(3, 20);
  aligned_delete(ptr,3);
  return 0;
}