# Saber Interactive

## Тест для соискателей вакансии Unreal Engine-программист

Уважаемый соискатель, перед Вами тест на вакансию Unreal Engine-программист в компании
Saber Interactive.  
  
Индустрия видеоигр, в которой работает наша, предъявляет высокие требования к качеству, эффективности и удобству восприятия программного кода. Поэтому мы предлагаем выполнить Вам 3 несложных задания, чтобы Вы могли продемонстрировать Вашу способность писать такой код.  
  
*Просьба не использовать в первой задаче библиотечные функции и классы, являющиеся решением этих задач (например stl::bitset).*

### Задачи

1. Напишите функцию, удаляющую последовательно дублирующиеся символы в строке:
("AAA BBB ААА" -> "A B А")

```C++
void RemoveDups (char *pStr);
```

2. Реализуйте функции сериализации и десериализации двусвязного списка в бинарном
формате в файл. **Алгоритмическая сложность должна быть быстрее квадратичной.**

```C++
struct ListNode {
    ListNode * prev;
    ListNode * next;
    ListNode * rand; // указатель на произвольный элемент данного списка либо NULL
    std::string data;
};

class List {
    public:
        void Serialize (FILE * file); // сохранение в файл (файл открыт с помощью fopen(path, "wb"))
        void Deserialize (FILE * file); // загрузка из файла (файл открыт с помощью fopen(path, "rb"))
    private:
        ListNode * head;
        ListNode * tail;
        int count;
};
```

*Примечание: сериализация подразумевает сохранение и восстановление полной структуры списка, включая взаимное соотношение его элементов между собой.*

3. Составить *BehaviourTree* (в виде схемы) для NPC, который в спокойном состоянии патрулирует территорию, по окончанию каждого патруля (окончанием считается возвращение в стартовую точку) NPC может или заснуть на 2 минуты или продолжить патруль. Когда у NPC есть враг, он атакует его, причем стрелять во врага может, только если у него есть патроны и враг на расстоянии меньше 30 метров. Если патронов нет, то NPC убегает от врага.

*Спасибо за уделенное время и выполнение нашего теста!*