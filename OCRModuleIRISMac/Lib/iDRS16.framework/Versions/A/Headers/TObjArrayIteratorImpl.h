#ifndef T_OBJ_ARRAY_ITERATOR_IMPL_H
#define T_OBJ_ARRAY_ITERATOR_IMPL_H

namespace std
{
#if defined(IDRS_OS_MACINTOSH) || defined(IDRS_OS_IOS)
  inline namespace __1 {
#elif defined(IDRS_OS_ANDROID)
  inline namespace __ndk1 {
#endif
  struct random_access_iterator_tag;
#if defined(IDRS_OS_MACINTOSH) || defined(IDRS_OS_IOS) || defined(IDRS_OS_ANDROID)
  }
#endif
}

namespace IDRS
{
  class CObj;

  template <typename T>
  struct RemoveConst
  {
    using type = T;
  };

  template <typename T>
  struct RemoveConst<const T>
  {
    using type = T;
  };

  template <typename T>
  class IDRSKRN_API TObjArrayIteratorImpl
  {
  public:
    using value_type = typename RemoveConst<T>::type;
    using reference = T&;
    using pointer = T*;
    using difference_type = decltype(static_cast<T*>(nullptr) - static_cast<T*>(nullptr));
    using iterator_category = std::random_access_iterator_tag;

    TObjArrayIteratorImpl(T* pobj) : m_pobj{ pobj }
    {}

    reference operator*() const
    {
      return *m_pobj;
    }

    pointer operator->() const
    {
      return m_pobj;
    }

    TObjArrayIteratorImpl& operator++()
    {
      ++m_pobj;
      return *this;
    }

    TObjArrayIteratorImpl operator++(int)
    {
      auto temp = *this;
      operator++();
      return temp;
    }

    TObjArrayIteratorImpl& operator--()
    {
      --m_pobj;
      return *this;
    }

    TObjArrayIteratorImpl operator--(int)
    {
      auto temp = *this;
      operator--();
      return temp;
    }

    TObjArrayIteratorImpl& operator+=(difference_type diff)
    {
      m_pobj += diff;
      return *this;
    }

    TObjArrayIteratorImpl& operator-=(difference_type diff)
    {
      m_pobj -= diff;
      return *this;
    }

    TObjArrayIteratorImpl operator+(difference_type diff) const
    {
      auto it = *this;
      it += diff;
      return it;
    }

    TObjArrayIteratorImpl operator-(difference_type diff) const
    {
      auto it = *this;
      it -= diff;
      return it;
    }

    bool operator==(const TObjArrayIteratorImpl& other) const
    {
      return m_pobj == other.m_pobj;
    }

    bool operator!=(const TObjArrayIteratorImpl& other) const
    {
      return !(*this == other);
    }

    difference_type operator-(const TObjArrayIteratorImpl& other) const
    {
      return m_pobj - other.m_pobj;
    }

  private:
    T* m_pobj;
  };

  template<typename T>
  struct IDRSKRN_API CObjArrayIteratorImpl
  {
  public:
    struct ReferenceProxy
    {
      operator T() const
      {
        return T{ m_obj };
      }

      ReferenceProxy& operator=(const T& obj)
      {
        m_obj->SubRef();
        m_obj = &obj.Object();
        m_obj->AddRef();
        return *this;
      }

      CObj*& m_obj;
    };

    struct PointerProxy
    {
      T* operator->()
      {
        return &m_obj;
      }

      T m_obj;
    };

    using difference_type = decltype(static_cast<CObj**>(nullptr) - static_cast<CObj**>(nullptr));
    using iterator_category = typename std::random_access_iterator_tag;
    using value_type = T;
    using reference = ReferenceProxy;
    using pointer = PointerProxy;

    CObjArrayIteratorImpl(CObj** it) : m_base{ it }
    {
    }

    reference operator*() const
    {
      return { *m_base };
    }

    pointer operator->() const
    {
      return { **this };
    }

    CObjArrayIteratorImpl& operator++()
    {
      ++m_base;
      return *this;
    }

    CObjArrayIteratorImpl operator++(int)
    {
      return { m_base++ };
    }

    CObjArrayIteratorImpl& operator--()
    {
      --m_base;
      return *this;
    }

    CObjArrayIteratorImpl operator--(int)
    {
      return { m_base-- };
    }

    CObjArrayIteratorImpl& operator+=(difference_type diff)
    {
      m_base += diff;
      return *this;
    }

    CObjArrayIteratorImpl operator-=(difference_type diff)
    {
      m_base -= diff;
      return *this;
    }

    CObjArrayIteratorImpl operator+(difference_type diff) const
    {
      return { m_base + diff };
    }

    CObjArrayIteratorImpl operator-(difference_type diff) const
    {
      return { m_base - diff };
    }

    bool operator==(const CObjArrayIteratorImpl& other) const
    {
      return m_base == other.m_base;
    }

    bool operator!=(const CObjArrayIteratorImpl& other) const
    {
      return m_base != other.m_base;
    }

    difference_type operator-(const CObjArrayIteratorImpl& other) const
    {
      return m_base - other.m_base;
    }

  private:
    CObj** m_base;
  };


  template<typename T>
  struct IDRSKRN_API CObjArrayConstIteratorImpl
  {
  public:
    struct ReferenceProxy
    {
      operator T() const
      {
        return T{ m_obj };
      }

      ReferenceProxy& operator=(const T& obj) = delete;

      CObj* const& m_obj;
    };

    struct PointerProxy
    {
      const T* operator->()
      {
        return &m_obj;
      }

      const T m_obj;
    };

    using difference_type = decltype(static_cast<CObj* const*>(nullptr) - static_cast<CObj* const*>(nullptr));
    using iterator_category = typename std::random_access_iterator_tag;
    using value_type = T;
    using reference = ReferenceProxy;
    using pointer = PointerProxy;

    CObjArrayConstIteratorImpl(CObj* const* it) : m_base{it}
    {
    }

    reference operator*() const
    {
      return { *m_base };
    }

    pointer operator->() const
    {
      return { **this };
    }

    CObjArrayConstIteratorImpl& operator++()
    {
      ++m_base;
      return *this;
    }

    CObjArrayConstIteratorImpl operator++(int)
    {
      return { m_base++ };
    }

    CObjArrayConstIteratorImpl& operator--()
    {
      --m_base;
      return *this;
    }

    CObjArrayConstIteratorImpl operator--(int)
    {
      return { m_base-- };
    }

    CObjArrayConstIteratorImpl& operator+=(difference_type diff)
    {
      m_base += diff;
      return *this;
    }

    CObjArrayConstIteratorImpl operator-=(difference_type diff)
    {
      m_base -= diff;
      return *this;
    }

    CObjArrayConstIteratorImpl operator+(difference_type diff) const
    {
      return { m_base + diff };
    }

    CObjArrayConstIteratorImpl operator-(difference_type diff) const
    {
      return { m_base - diff };
    }

    bool operator==(const CObjArrayConstIteratorImpl& other) const
    {
      return m_base == other.m_base;
    }

    bool operator!=(const CObjArrayConstIteratorImpl& other) const
    {
      return m_base != other.m_base;
    }

    difference_type operator-(const CObjArrayConstIteratorImpl& other) const
    {
      return m_base - other.m_base;
    }

  private:
    CObj* const* m_base;
  };


}

#endif