#include <iostream>
int money, energy, psychics, knowledge, examCount = 0;

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

void printBeginGame() {
    std::cout << "||======================================||" << std::endl;
    std::cout << "||  🎓  ПОЗДРАВЛЕНИЯ!                   ||" << std::endl;
    std::cout << "||  [1] Започване на нова игра          ||" << std::endl;
    std::cout << "||  [2] Зареждане на игра от файл       ||" << std::endl;
    std::cout << "||======================================||" << std::endl;
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
    printMenu();
}
