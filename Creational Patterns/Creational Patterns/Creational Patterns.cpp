#include <iostream> 
#include <Windows.h>

using namespace std;



class Character 
{
public:
    virtual string getType() = 0;
    virtual void attack() = 0;
    virtual int getHealth() = 0;
};
/// \brief Класс с настройками для персонажа Воин
class Warrior : public Character 
{
public:
    /**
    * brief Функция для получения типа персонажа
    * return string - сторку, название персонажа
    * remark Получаем только имя персонажа т.к. это учебный код
    */
    string getType() override { return "Воин с здоровьем "; }
    /**
    * brief Функция для обозначения здоровья персонажа
    */
    int getHealth() override { return 100; }
    /**
    * brief Функция для выполнения действий персонажа
    * note Не влияет ни на что. Это учебный код
    * todo Добавить возможность отбирать жизни у того, на кого нападаем
    */
    void attack() override { cout << "Воин атакует мечом!" << endl; }
};
/// \brief Класс с настройками для персонажа Маг
class Mage : public Character
{
public:
    /**
    * brief Функция для получения типа персонажа
    * return string - сторку, название персонажа
    * remark Получаем только имя персонажа т.к. это учебный код
    */
    string getType() override { return "Маг с здоровьем "; }
    /**
    * brief Функция для обозначения здоровья персонажа
    */
    int getHealth() override { return 50; }
    /**
    * brief Функция для выполнения действий персонажа
    * note Не влияет ни на что. Это учебный код
    * todo Добавить возможность отбирать жизни у того, на кого нападаем
    */
    void attack() override { cout << "Маг кастует огненный шар!" << endl; }
};
/// \brief Класс с настройками для персонажа Лучник
class Archer : public Character
{
public:
    /**
    * brief Функция для получения типа персонажа
    * return string - сторку, название персонажа
    * remark Получаем только имя персонажа т.к. это учебный код
    */
    string getType() override { return "Лучник с здоровьем "; }
    /**
    * brief Функция для обозначения здоровья персонажа
    */
    int getHealth() override { return 70; }
    /**
    * brief Функция для выполнения действий персонажа
    * note Не влияет ни на что. Это учебный код
    * todo Добавить возможность отбирать жизни у того, на кого нападаем
    */
    void attack() override { cout << "Лучник стреляет из лука!" << endl; }
};
/// \brief Класс с настройками для персонажа Рыцарь
class Knight : public Character
{
public:
    /**
    * brief Функция для получения типа персонажа
    * return string - сторку, название персонажа
    * remark Получаем только имя персонажа т.к. это учебный код
    */
    string getType() override { return "Рыцарь с здоровьем "; }
    /**
    * brief Функция для обозначения здоровья персонажа
    */
    int getHealth() override { return 80; }
    /**
    * brief Функция для выполнения действий персонажа
    * note Не влияет ни на что. Это учебный код
    * todo Добавить возможность отбирать жизни у того, на кого нападаем
    */
    void attack() override { cout << "Рыцарь атакует копьем!" << endl; }
};

/**
brief Абстрактная фабрика для генерации персонажей

Используется для примера работы паттерна проектирования Creational
*/
class CharacterFactory
{
public:
    virtual Character* createCharacter() = 0;
    /**
    * brief Функция для создания персонажей и выполнения базовых его действий
    * note После создания объеката, выполняет действие персонажа и уничтожает объект
    * warning Нельзя будет использовать созданных персонажей в других частях кода
    */
    void spawnAndAttack()
    {
        Character* chara = createCharacter();
        cout << "Создан " << chara->getType() << chara->getHealth() << ". ";
        chara->attack();
        delete chara;
    }
};

/// \brief Класс для создания Воина
class WarriorFactory : public CharacterFactory
{
public:
    /**
    * brief Функция для выделения памяти на класс персонажа
    * return Возвращает указатель на созданного персонажа
    */
    Character* createCharacter() override { return new Warrior(); }
};

/// \brief Класс для создания Мага
class MageFactory : public CharacterFactory
{
public:
    /**
    * brief Функция для выделения памяти на класс персонажа
    * return Возвращает указатель на созданного персонажа
    */
    Character* createCharacter() override { return new Mage(); }
};

/// \brief Класс для создания Лучника
class ArcherFactory : public CharacterFactory
{
public:
    /**
    * brief Функция для выделения памяти на класс персонажа
    * return Возвращает указатель на созданного персонажа
    */
    Character* createCharacter() override { return new Archer(); }
};

/// \brief Класс для создания Рыцаря
class KnightFactory : public CharacterFactory
{
public:
    /**
    * brief Функция для выделения памяти на класс персонажа
    * return Возвращает указатель на созданного персонажа
    */
    Character* createCharacter() override { return new Knight(); }
};

/// \brief Функция для запуска конвеера с персонажами
/// \note Используется для учебного коды
int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    // Симуляция игры: создаем разных персонажей через фабрику
    CharacterFactory* factory = new WarriorFactory();
    factory->spawnAndAttack(); // Вывод: Создан Воин.

    factory = new MageFactory();
    factory->spawnAndAttack(); // Вывод: Создан Маг.

    factory = new ArcherFactory();
    factory->spawnAndAttack(); // Вывод: Создан Лучник.

    factory = new KnightFactory();
    factory->spawnAndAttack(); // Вывод: Создан Рыцарь.

    delete factory;
}
