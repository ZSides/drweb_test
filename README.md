# drweb_test
Тестовое задание в dr.web

# условие 1 (main.cpp)
Напишите функцию, которая обрезает пробелы в конце переданной ей строки. Функция должна быть написана в расчёте на работу с очень длинными строками с очень большим количеством пробелов, оптимизирована по количеству обращений к памяти. Сигнатура: `void TrimRight( char *s );`

# условие 2 (main2.cpp)
Необходимо реализовать класс контейнера, реализующий интерфейс Dictionary и способный выбросить исключение, реализующее интерфейс NotFoundException.
При разработке допускается использовать STL. Кроме этого, внутренняя реализация ничем не ограничена.
```
template<class TKey, class TValue>
  class Dictionary
  {
  public:
      virtual ~Dictionary() = default;
  
      virtual const TValue& Get(const TKey& key) const = 0;
      virtual void Set(const TKey& key, const TValue& value) = 0;
      virtual void Remove(const TKey& key) = 0;
      virtual bool IsSet(const TKey& key) const = 0;
  };
  
  template<class TKey>
  class NotFoundException : public std::exception
  {
  public:
      virtual const TKey& GetKey() const noexcept = 0;
  }; 
```

# условие 3 (main3.cpp)
Необходимо реализовать функцию.
Прототип функции: `void join(const std::vector< int > &from, std::vector< int > &to);`

Она должна принимать два отсортированных вектора (отсортированность принимается на веру - проверять не нужно, порядок - по возрастанию). На выходе вектор from не изменяется, а вектор to содержит все элементы из обоих, так же расположенных в порядке возрастания.
