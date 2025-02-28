# Building a project
`build` - процесa *(или резултатa от него)* по превръщане на кода в самостоятелни софтуерни артефакти, които могат да се изпълняват на компютъра

## `build` vs. `compile`?
`build` се отнася за целия процес: `preprocessing` - `compiling` - `linking` - ако има и някакви други задачи     

- `preprocessing` - променя кода като изпълнява директивите въведени с `#` - вмъква код, тества за някакви условия за компилация и др.
- `compiling` - превръща сорс кода в object/машинен код
- `linking` - комбинира машинния код в един изпълним файл

### Кои процеси трябва да се преизпълняват при промяна?
- Ако сте променили само един `.cpp` файл, достатъчно е да прекомпилирате само него и отново да свържете обектите. 
- Ако промените `.h` файл, всички изходни файлове, които включват този хедър, трябва да бъдат прекомпилирани.

### Как работят build системите?
1. Пишем build script
2. Скрипта пуска компилатора за всеки сорс файл, използвайки зададените в build script-a [параметри](https://gist.github.com/g-berthiaume/74f0485fbba5cc3249eee458c1d0d386):
    ```
    g++ -o src1.o src1.cpp
    g++ -o src2.o src2.cpp
    g++ -o src3.o src3.cpp
    ```
3. Скрипта пуска линкера, който ги свързва в изпълнима програма:
    ```
    g++ -o program.exe src1.o src2.o src3.o
    ```
Каква е ползата: 
- Ако нещо променим, системата преценява какво да се прекомпилира
- Не се налага ръчно да се грижим за това и да помним кое сме променяли и кое - не 
- Не се налага всичко да прекомпилираме по 30 пъти, когато дебъгваме например

# CMake
1. Пишем build script 
2. Скрипта генерира build script за build системата на нашия компютър и оставя тя да компилира програмата

Каква е ползата:    
- Позволява да имаме написан един билд скрипт, който можем да си викаме без никакви промени по него, независимо върху каква билд система и устройство работим.

[CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)       
[CMake Project in Visual Studio](https://learn.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=msvc-170#installation)