# AA Tree

[![CMake](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-AA-Trees-by-DjangoGirls/actions/workflows/cmake.yml/badge.svg?branch=main)](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-AA-Trees-by-DjangoGirls/actions/workflows/cmake.yml)

_Краткое описание семестрового проекта. Следует отразить информацию по следующим пунктам:_

- _Какая структура данных реализуется?_
- _Что она из себя представляет (сбалансированное дерево, линейный список и пр.)?_
- _Где и как она используется (приложения)?_
- _Какие операции над ней можно выполнять (поиск, удаление, добавление, вставка и пр.)?_
- _Какова теоретическая сложность операций (поиск за `O(log(n))`, вставка за `O(n^2)` и т.д.)?_
- _Какая-то другая справочная информация о проекте._

АA-дерево — структура данных, представляющая собой сбалансированное двоичное дерево поиска, которое является разновидностью красно-черного дерева с дополнительными ограничениями.
В своих работах Arne Andersson приводит простое правило, которому должно удовлетворять AA-дерево: к одной вершине можно присоединить другую вершину того же уровня но только одну и только справа.
Таким образом, введенное понятие уровня вершины не всегда совпадает с реальной высотой вершины (расстояния от земли), но дерево сохраняет балансировку при следовании правилу «одна правая связь на одном уровне».

Пример использования :
Использование
АА-дерево можно использовать для создания и ведения упорядоченных списков, где нам будет нужно больше искать значения, а не добавлять или удалять их.
Например для поиска домов на карте, так как новые дома строятся не так часто, а получать их расположение нужно довольно часто, то неплохим выбором бдует использование АА-дерева.

Операции:
Skew - устранение левого горизонтального ребра. Делаем правое вращение, чтобы заменить поддерево, содержащее левую горизонтальную связь, на поддерево, содержащее разрешенную правую горизонтальную связь.
Split - устранение двух последовательных правых горизонтальных ребер. Делаем левое вращение и увеличиваем уровень, чтобы заменить поддерево, содержащее две или более последовательных правильных горизонтальных связи, на вершину, содержащую два поддерева с меньшим уровнем.
Insert - вставка вершины. Как и положено почти любому дереву поиска, вставляем новое значение среди листьев дерева (приписывая ему минимальную высоту). Потом вызываем Split (вернее Split(Skew()) ) для всех узлов по пути от листа до корня. Чем имтируем обычное расщепление 2-3 узлов.
Remove - удаление вершины. Как и в большинстве сбалансированных бинарных деревьев, удаление внутренней вершины можно заменить на удаление листа, если заменить внутреннюю вершину на ее ближайшего предшественника. Предшественник находиться в начале последнего левого ребра, после которого идут все правые ребра. В силу свойства всех узлов уровня более чем 1, имеющих двух детей, предшественник будет на уровне 1, что делает их удаление тривиальным. После мы вызываем Split для каждого узла и приводим дерево в подходящий вид.

Сложность операций и требование по памяти: Затраты по памяти - O(n) Splay - O(log(n)) Search - O(log(n)) Split - O(log(n)) Insert - O(log(n)) Remove - O(log(n))


Свойства АА-дерева
Уровень каждого листа равен 1.
Уровень каждого левого ребенка ровно на один меньше, чем у его родителя.
Уровень каждого правого ребенка равен или на один меньше, чем у его родителя.
Уровень каждого правого внука строго меньше, чем у его прародителя.
Каждая вершина с уровнем больше 1 имеет двоих детей.
В отличие от красно-черных деревьев, к одной вершине можно присоединить вершину только того же уровня, только одну и только справа (другими словами, красные вершины могут быть добавлены только в качестве правого ребенка).
На практике в AA-дереве вместо значения цвета для балансировки дерева в вершине хранится информация только о ее уровне.
В AA-дереве разрешены правые ребра, не идущие подряд, и запрещены все левые горизонтальные ребра. Эти более жесткие ограничения, аналогичные ограничениям на красно-черных деревьях, приводят к более простой реализации балансировки AA-дерева.


## Команда "Ходячие(не на пары)"


| Фамилия Имя`       `| Вклад (%) | Должность             |

| :`       `---`       `|`   `---:`    `|`  `---:`                 `|

| Cуржиков Ярослав`  `| 33.(3)`    `|`  `Идейный вдохновитель |

| Яковлев Алмаз`     `| 33.(3)`    `|`  `Душа компании`        `|

| Сивачев Никита`    `| 33.(3)`    `|`  `Генеральный аводила`  `|



**Девиз команды**
То, что мертво, умереть не может.

## Структура проекта

**Пример**. Проект состоит из следующих частей:

- [`src`](src)/[`include`](include) - реализация структуры данных (исходный код и заголовочные файлы);
- [`benchmark`](benchmark) - контрольные тесты производительности структуры данных (операции добавления, удаления,
  поиска);
- [`examples`](examples) - примеры работы со структурой данных;
- [`dataset`](dataset)/['data'](data) - наборы данных для запуска контрольных тестов, их генерация и результаты выполнения;

## Требования (Prerequisites)

_В этом разделе задаются основые требования к программному и аппаратному обеспечению для успешной работы с проектом._

**Пример**. Рекомендуемые требования:

1. С++ компилятор c поддержкой стандарта C++17 (например, _GNU GCC 8.1.x_ и выше).
2. Система автоматизации сборки _CMake_ (версия _3.12.x_ и выше).
3. Интерпретатор _Python_ (версия _3.7.x_ и выше).
4. Рекомендуемый объем оперативной памяти - не менее 4 ГБ.
5. Свободное дисковое пространство объемом ~ 3 ГБ (набор данных для контрольных тестов).

## Сборка и запуск

_Инструкция по сборке проекта, генерации тестовых данных, запуска контрольных тестов и примеров работы._

_Постарайтесь написать инструкцию так, чтобы незнакомый с проектом человек смог самостоятельно всё запустить._

### Пример (Windows)

#### Сборка проекта

Склонируйте проект к себе на устройство через [Git for Windows](https://gitforwindows.org/) (либо используйте
возможности IDE):

```shell
git clone https://github.com/Algorithms-and-Data-Structures-2021/semester-work-template.git
```

Для ручной сборки проекта в терминале введите:

```shell
# переход в папку с проектом
cd C:\Users\username\asd-projects\semester-work-template

# создание папки для файлов сборки (чтобы не засорять папку с проектом) 
mkdir -p build && cd build 

# сборка проекта
cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo && cmake --config RelWithDebInfo --build . 
```

#### Генерация тестовых данных


Генерация тестового набора данных в
формате TXT.

```shell
# переход в папку генерации набора данных
cd dataset

# запуск Python-скрипта
python generator_v2.py


```

По названию директории `/dataset/data/add` можно понять, что здесь хранятся наборы данных для контрольных тестов по
**добавлению** элементов в структуру данных. Названия файлов `100.txt`. `5000000.txt` и т.д. хранят информацию о размере набора данных (т.е. количество элементов). 

#### Контрольные тесты (benchmarks)

_Опишите, как запустить контрольные тесты, что они из себя представляют, какие метрики замеряют (время работы,
потребление памяти и пр.)._

Для запуска контрольных тестов необходимо предварительно сгенерировать или скачать готовый набор тестовых данных.

Google Drive : https://drive.google.com/drive/u/0/folders/1Ck2lKt4nP6osSQwloiLW9ppLJjRJDN4j

##### Список контрольных тестов

| Название                  | Описание                                | Метрики         |
| :---                      | ---                                     | :---            |
| `demo_benchmark`          | Добавление, поиск и удаление            | Замер времени
| ...                       | ...                                     | ...             |


## Источники

Викиконспекты : https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwiBssq_xpnwAhVok4sKHV0eA0gQFjAAegQIAhAD&url=https%3A%2F%2Fneerc.ifmo.ru%2Fwiki%2Findex.php%3Ftitle%3DAA-%25D0%25B4%25D0%25B5%25D1%2580%25D0%25B5%25D0%25B2%25D0%25BE&usg=AOvVaw2Bx1BlE7DiRw46ecFPH9GG 

Habr.com : https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwiBssq_xpnwAhVok4sKHV0eA0gQFjABegQIAxAD&url=https%3A%2F%2Fhabr.com%2Fru%2Fpost%2F110212%2F&usg=AOvVaw2bTC95l1THC9Cjffaqp1XD

qaz.wiki : https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwiBssq_xpnwAhVok4sKHV0eA0gQFjABegQIAxAD&url=https%3A%2F%2Fhabr.com%2Fru%2Fpost%2F110212%2F&usg=AOvVaw2bTC95l1THC9Cjffaqp1XD