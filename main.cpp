#include <iostream>
#include <fstream>
#include <limits>
int money, energy, psychics, knowledge, examCount = 0;

void printBeginGame() {
    std::cout << "||======================================||" << std::endl;
    std::cout << "||  🎓  ПОЗДРАВЛЕНИЯ!                   ||" << std::endl;
    std::cout << "||  [1] Започване на нова игра          ||" << std::endl;
    std::cout << "||  [2] Зареждане на игра от файл       ||" << std::endl;
    std::cout << "||======================================||" << std::endl;
}

void beginGame(int n) {
    if (n == 1) {
        std::ofstream game("game.txt");
        game.close();
    }
    if (n == 2) {
        std::ifstream game("game.txt");
    }
}

void printDifficultyLevel() {
    std::cout << "||======================================||" << std::endl;
    std::cout << "||  Избери начално ниво                 ||" << std::endl;
    std::cout << "||  [1] Лесно                           ||" << std::endl;
    std::cout << "||  [2] Нормално                        ||" << std::endl;
    std::cout << "||  [3] Трудно                          ||" << std::endl;
    std::cout << "||======================================||" << std::endl;
}

void difficultyLevel(int n) {
    if (n == 1) {
        knowledge = 80;
        energy = 100;
        money = 100;
        psychics = 100;
    }
    if (n == 2) {
        knowledge = 50;
        energy = 80;
        money = 80;
        psychics = 80;
    }
    if (n == 3) {
        knowledge = 35;
        money = 60;
        energy = 60;
        psychics = 40;
    }
}

void printMenu() {
    std::cout << "Какво искаш да направиш днес?" << std::endl;
    std::cout << "[1] Учиш" << std::endl;
    std::cout << "[2] Храниш се" << std::endl;
    std::cout << "[3] Излизаш" << std::endl;
    std::cout << "[4] Почиваш" << std::endl;
    std::cout << "[5] Работиш" << std::endl;
    std::cout << "[6] Явяваш се на изпит (ако е време)" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "[11] Излез от играта" << std::endl;
}

void menu(int n) {
    
    switch (n) {
        case 1:study();
    }
}

void study() {
    knowledge += 20;
    energy -= 20;
    psychics -= 10;
}

void eat() {
    energy += 20;
    money -= 10;
    psychics += 5;
}

void goOut() {
    psychics += 40;
    money -= 25;
    energy -= 15;
}

void sleep() {
    energy += 50;
    psychics += 10;
}

void work() {
    money += 40;
    energy -= 20;
    psychics -= 10;
}

void goToExam() {
    energy -= 20;
}


void printEndGame() {
    std::cout << "||======================================||" << std::endl;
    std::cout << "||  🎓  ПОЗДРАВЛЕНИЯ!                   ||" << std::endl;
    std::cout << "||  Взе всички изпити и оцеля           ||" << std::endl;
    std::cout << "||  в сесията на живота си!             ||" << std::endl;
    std::cout << "||======================================||" << std::endl;
}

void lostGame() {
    std::cout << "||======================================||" << std::endl;
    std::cout << "||  💥 ИГРАТА ПРИКЛЮЧИ!                 ||" << std::endl;
    std::cout << "||  Твоята психика не издържа           ||" << std::endl;
    std::cout << "||  и си напуснал университета          ||" << std::endl;
    std::cout << "||======================================||" << std::endl;
}

void printStudentStatus() {
    std::cout << "||======================================||" << std::endl;
    std::cout << "||  Ден <day> от 30                     ||" << std::endl;
    std::cout << "||  Пари: <money> лв                    ||" << std::endl;
    std::cout << "||  Енергия: <energy> ⚡                 ||" << std::endl;
    std::cout << "||  Психика: <psychics> 🧠              ||" << std::endl;
    std::cout << "||  Знания: <knowledge> 📚              ||" << std::endl;
    std::cout << "||  Взети изпити: <examCount> 🎓        ||" << std::endl;
    std::cout << "||======================================||" << std::endl;
}

int main() {
    printBeginGame();
    int beginGameOption;
    do {
        std::cout << "Избери опция 1 или 2:";
        std::cin >> beginGameOption;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
    } while (beginGameOption != 1 && beginGameOption != 2);
    beginGame(beginGameOption);
    if (beginGameOption == 1) {
        printDifficultyLevel();
        int DifficultyLevelOption;
        do {
            std::cout << "Избери опция 1 или 2 или 3:";
            std::cin >> DifficultyLevelOption;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
        } while (DifficultyLevelOption != 1 && DifficultyLevelOption != 2 && DifficultyLevelOption != 3);
        difficultyLevel(DifficultyLevelOption);
    }
    printMenu();
    int menuOptions;
    do {
        std::cout << "Избери опция 1 или 2:";
        std::cin >> menuOptions;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
    } while (menuOptions != 1 && menuOptions != 2 && menuOptions != 3 && menuOptions != 4 && menuOptions != 5 &&
             menuOptions != 6 && menuOptions != 7 && menuOptions != 8 && menuOptions != 9 && menuOptions != 10 &&
             menuOptions != 11 && menuOptions != 12);
    menu(menuOptions);
}
