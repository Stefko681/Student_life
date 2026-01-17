/**
*
* Solution to course project # 11
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2025/2026
*
* @author Stefko Nikolaev
* @idnumber 6MI0600647
* @compiler GCC
*
* <main file>
*
*/


#include <iostream>
#include <fstream>
#include <limits>
#include <random>

//========CONSTANTS=============
const int MAX_PARAMETER_VALUE = 100;
const int EXAM_1_DAY = 8;
const int EXAM_2_DAY = 17;
const int EXAM_3_DAY = 26;
const int EXAM_5_DAY = 45;
const char *SAVE_FILE = "game.txt";

//======STRUCT_FOR_STATS========
struct GameState {
    double money;
    double energy;
    double psychics;
    double knowledge;
    double successfulExams;
    int day;
    int examNumber;
    int failedExams;
    int exam4Day;
};

//=========RANDOM_GENERATOR==============
int randomNumber(std::mt19937 &gen, const int min, const int max) {
    std::uniform_int_distribution<int> range(min, max);
    return range(gen);
}


//=====MAX_PARAMETER_RULES====
void parameterRestrictions(GameState &state) {
    if (state.energy > MAX_PARAMETER_VALUE) {
        state.energy = MAX_PARAMETER_VALUE;
    }
    if (state.psychics > MAX_PARAMETER_VALUE) {
        state.psychics = MAX_PARAMETER_VALUE;
    }
    if (state.knowledge > MAX_PARAMETER_VALUE) {
        state.knowledge = MAX_PARAMETER_VALUE;
    }
}

//=====LOW_ENERGY_RULE=====
bool checkLowEnergyFail(std::mt19937 &gen, const double energy) {
    int randomNum = randomNumber(gen, 1, 100);
    if (energy < 40 && randomNum > 50) return true;
    if (energy < 80 && randomNum > 75) return true;
    return false;
}

//====ENERGY_LESS_THAN_ZERO_RULE====
void energyLessThanZero(GameState &state) {
    std::cout << "You passed out! Energy < 0. You miss the next day." << std::endl;
    state.day++;
    state.energy = 40;
    state.psychics -= 10;
}

//=====MESSAGE_FOR_LOW_ENERGY_RULE=====
void tooLowEnergyMessage() {
    std::cout << "Your energy is low and unfortunately the effectiveness of half of the action is activated!" <<
            std::endl;
}

//======RANDOM_EVENT_FOR_EVERY_MAIN_EVENT=====
void studyRandomEvents(std::mt19937 &gen, GameState &state) {
    int rand = randomNumber(gen, 1, 100);
    if (rand <= 5) {
        state.knowledge += 15;
        std::cout << "Everything became clear! +15 Knowledge!" << std::endl;
    } else if (rand <= 15) {
        state.knowledge += 5;
        state.psychics += 5;
        std::cout << "A colleague sent you notes. +5 Knowledge, +5 Psychics!" << std::endl;
    } else if (rand <= 27) {
        state.energy -= 10;
        std::cout << "You studied too much, your eyes hurt. -10 Energy!" << std::endl;
    } else if (rand <= 34) {
        state.psychics -= 15;
        std::cout << "Neighbors are drilling while you study. -15 Psychics!" << std::endl;
    }
}


//======RANDOM_EVENTS_FOR_ACTIONS====
void workRandomEvents(std::mt19937 &gen, GameState &state) {
    int rand = randomNumber(gen, 1, 100);
    if (rand <= 10) {
        state.money += 15;
        std::cout << "The client was happy. +15 Money!" << std::endl;
    } else if (rand <= 12) {
        state.money += 20;
        std::cout << "You found 20 BGN on the street. +20 Money!" << std::endl;
    } else if (rand <= 17) {
        state.money -= 15;
        std::cout << "You broke something at work. -15 Money!" << std::endl;
    } else if (rand <= 27) {
        state.energy -= 15;
        std::cout << "Overtime work. -15 Energy!" << std::endl;
    }
}

void goOutRandomEvents(std::mt19937 &gen, GameState &state) {
    int rand = randomNumber(gen, 1, 100);
    if (rand <= 4) {
        state.money += 15;
        std::cout << "A stranger paid the bill. +15 Money!" << std::endl;
    } else if (rand <= 9) {
        state.psychics += 30;
        std::cout << "You met someone special. +30 Psychics!" << std::endl;
    } else if (rand <= 11) {
        state.money -= 40;
        std::cout << "You lost your wallet. -40 Money!" << std::endl;
    } else if (rand <= 32) {
        state.energy -= 20;
        std::cout << "Wild party. -20 Energy!" << std::endl;
    }
}

void eatRandomEvents(std::mt19937 &gen, GameState &state) {
    int rand = randomNumber(gen, 1, 100);
    if (rand <= 10) {
        state.psychics += 5;
        std::cout << "Promotion at the duner shop. +5 Psychics!" << std::endl;
    } else if (rand <= 15) {
        state.energy -= 20;
        std::cout << "Bad food poisoning... -20 Energy!" << std::endl;
    }
}

void sleepRandomEvents(std::mt19937 &gen, GameState &state) {
    int rand = randomNumber(gen, 1, 100);
    if (rand <= 7) {
        state.psychics -= 10;
        std::cout << "Nightmare about exams. -10 Psychics!" << std::endl;
    } else if (rand <= 17) {
        state.energy -= 25;
        std::cout << "Party next door until 3 AM. -25 Energy!" << std::endl;
    }
}


//======CHANGE_STATS============
void goToLessons(std::mt19937 &gen, GameState &state) {
    state.knowledge += 20;
    state.energy -= 20;
    state.psychics -= 10;
    std::cout << "You attended lectures. +20 Knowledge, -20 Energy, -10 Psychics." << std::endl;
    studyRandomEvents(gen, state);
    int randomNum = randomNumber(gen, 1, 100);
    if (state.energy < 40 && randomNum > 50) {
        state.knowledge -= 10;
        tooLowEnergyMessage();
    } else if (state.energy < 80 && randomNum > 75) {
        state.knowledge -= 10;
        tooLowEnergyMessage();
    }
    parameterRestrictions(state);
}

void studyHome(std::mt19937 &gen, GameState &state) {
    state.knowledge += 20;
    state.energy -= 15;
    state.psychics -= 20;
    std::cout << "You studied at home. +20 Knowledge, -15 Energy, -20 Psychics." << std::endl;
    studyRandomEvents(gen, state);
    if (checkLowEnergyFail(gen, state.energy)) {
        state.knowledge -= 10;
        tooLowEnergyMessage();
    }
    parameterRestrictions(state);
}

void studyWithFriends(std::mt19937 &gen, GameState &state) {
    state.knowledge += 5;
    state.energy -= 10;
    state.psychics += 10;
    std::cout << "You studied with friends. +5 Knowledge, -10 Energy, +10 Psychics." << std::endl;
    studyRandomEvents(gen, state);
    if (checkLowEnergyFail(gen, state.energy)) {
        state.knowledge -= 10;
        tooLowEnergyMessage();
    }
    parameterRestrictions(state);
}

void eat(std::mt19937 &gen, GameState &state) {
    state.energy += 20;
    state.money -= 10;
    state.psychics += 5;
    std::cout << "You ate something. +20 Energy, -10 Money, +5 Psychics." << std::endl;
    eatRandomEvents(gen, state);
    if (checkLowEnergyFail(gen, state.energy)) {
        state.knowledge -= 10;
        tooLowEnergyMessage();
    }
    parameterRestrictions(state);
}

void goOut(std::mt19937 &gen, GameState &state) {
    state.psychics += 40;
    state.money -= 25;
    state.energy -= 15;
    std::cout << "You went out. -15 Energy, -25 Money, +40 Psychics." << std::endl;
    goOutRandomEvents(gen, state);
    int randomNum = randomNumber(gen, 1, 100);
    if (state.energy < 40 && randomNum > 50) {
        state.psychics -= 20;
        tooLowEnergyMessage();
    } else if (state.energy < 80 && randomNum > 75) {
        state.psychics -= 20;
        tooLowEnergyMessage();
    }
    parameterRestrictions(state);
}

void sleep(std::mt19937 &gen, GameState &state) {
    state.energy += 50;
    state.psychics += 10;
    std::cout << "You slept well. +50 Energy, +10 Psychics." << std::endl;
    sleepRandomEvents(gen, state);
    parameterRestrictions(state);
}

void work(std::mt19937 &gen, GameState &state) {
    state.money += 40;
    state.energy -= 20;
    state.psychics -= 10;
    std::cout << "You went to work. -20 Energy, +40 Money, -20 Psychics." << std::endl;
    workRandomEvents(gen, state);
    if (checkLowEnergyFail(gen, state.energy)) {
        state.knowledge -= 10;
        tooLowEnergyMessage();
    }
    parameterRestrictions(state);
}

void goToExam(std::mt19937 &gen, GameState &state) {
    state.energy -= 20;
    int luck = randomNumber(gen, 1, 100);
    double penalty = (state.examNumber - 1) * 5;
    double success = (state.knowledge * 0.75) + (state.psychics * 0.1) + (state.energy * 0.1) + (luck * 0.2) - penalty;
    if (success >= 75.0) {
        state.successfulExams++;
        state.psychics += 20;
        std::cout << "Congratulations! You passed the exam!" << std::endl;
    } else {
        state.psychics -= 30;
        std::cout << "Unfortunately, you failed the exam." << std::endl;
        state.failedExams++;
    }
    state.examNumber++;
    if (checkLowEnergyFail(gen, state.energy)) {
        state.knowledge -= 10;
        tooLowEnergyMessage();
    }
    parameterRestrictions(state);
}

//======BEGIN_GAME_MESSAGE======
void printBeginGame() {
    std::cout << "||======================================||" << std::endl;
    std::cout << "||  WELCOME TO STUDENT SIMULATOR        ||" << std::endl;
    std::cout << "||  [1] New Game                        ||" << std::endl;
    std::cout << "||  [2] Load Game                       ||" << std::endl;
    std::cout << "||======================================||" << std::endl;
}

//========DIFFICULTY_OPTIONS_MESSAGE========
void printDifficultyLevel() {
    std::cout << "||======================================||" << std::endl;
    std::cout << "||  Choose difficulty level             ||" << std::endl;
    std::cout << "||  [1] Easy                            ||" << std::endl;
    std::cout << "||  [2] Normal                          ||" << std::endl;
    std::cout << "||  [3] Hard                            ||" << std::endl;
    std::cout << "||======================================||" << std::endl;
}

//======PARAMETERS_FOR_DIFFICULTLY_LEVELS====
void difficultyLevel(GameState &state, const int n) {
    if (n == 1) {
        state.knowledge = 80;
        state.energy = 100;
        state.money = 100;
        state.psychics = 100;
    }
    if (n == 2) {
        state.knowledge = 50;
        state.energy = 80;
        state.money = 80;
        state.psychics = 80;
    }
    if (n == 3) {
        state.knowledge = 35;
        state.money = 60;
        state.energy = 60;
        state.psychics = 40;
    }
}

//======PRINT_STUDENT_STATS====
void printStudentStatus(const GameState &state) {
    std::cout << "\n||==========================================||" << std::endl;
    std::cout << "||  Day: " << state.day << " of 45\t\t\t\t\t\t\t||" << std::endl;
    std::cout << "||  Money: " << state.money << " BGN\t\t\t\t\t\t\t||" << std::endl;
    std::cout << "||  Energy: " << state.energy << "\t\t\t\t\t\t\t\t||" << std::endl;
    std::cout << "||  Psychics: " << state.psychics << "\t\t\t\t\t\t\t||" << std::endl;
    std::cout << "||  Knowledge: " << state.knowledge << "\t\t\t\t\t\t\t||" << std::endl;
    std::cout << "||  Passed Exams: " << state.successfulExams << "\t\t\t\t\t\t\t||" << std::endl;
    if (state.failedExams != 0) {
        std::cout << "||  Failed Exams: " << state.failedExams << "\t\t\t\t\t\t\t||" << std::endl;
    }
    std::cout << "||==========================================||" << std::endl;
}

//======PRINT_DAILY_MENU====
void printMenu(const GameState &state) {
    std::cout << "What do you want to do today?" << std::endl;
    std::cout << "[1] Study" << std::endl;
    std::cout << "[2] Eat" << std::endl;
    std::cout << "[3] Go Out" << std::endl;
    std::cout << "[4] Sleep" << std::endl;
    std::cout << "[5] Work" << std::endl;
    std::cout << "[6] Take Exam (if it is time)" << std::endl;
    std::cout << "[7] Save & Exit" << std::endl;
    if (state.failedExams != 0) {
        std::cout << "[8] Retake Exam (Penalty): " << state.failedExams << std::endl;
    }
}


//======PRINT_STUDY_OPTIONS=====
void printStudyOptions() {
    std::cout << "Choose study type:" << std::endl;
    std::cout << "[1] Go to lectures" << std::endl;
    std::cout << "[2] Study at home" << std::endl;
    std::cout << "[3] Study with friends" << std::endl;
}


//====CHOOSE_STUDY_OPTION====
void studyOptions(std::mt19937 &gen, GameState &state, const int n) {
    if (n == 1) {
        goToLessons(gen, state);
    }
    if (n == 2) {
        studyHome(gen, state);
    }
    if (n == 3) {
        studyWithFriends(gen, state);
    }
}


//CHOOSE_MENU_OPTION====
void menu(std::mt19937 &gen, GameState &state, const int n) {
    switch (n) {
        case 2: eat(gen, state);
            break;
        case 3: goOut(gen, state);
            break;
        case 4: sleep(gen, state);
            break;
        case 5: work(gen, state);
            break;
        case 6: if (state.day == EXAM_1_DAY || state.day == EXAM_2_DAY || state.day == EXAM_3_DAY || state.day == state.
                    exam4Day || state.day ==
                    EXAM_5_DAY) {
                goToExam(gen, state);
            }
            break;
        case 7: break;
        case 8: if (state.failedExams != 0) {
                goToExam(gen, state);
            }
        default: return;
    }
}


//=====WIN_GAME_MESSAGE====
void printWinGame() {
    std::cout << "||======================================||" << std::endl;
    std::cout << "||  🎓  CONGRATULATIONS!                ||" << std::endl;
    std::cout << "||  Took all the exams and survived     ||" << std::endl;
    std::cout << "||  in the session of a lifetime!       ||" << std::endl;
    std::cout << "||======================================||" << std::endl;
}


//======LOST_GAME_MESSAGE====
void printLostGame() {
    std::cout << "||======================================||" << std::endl;
    std::cout << "||  💥 GAME OVER!                       ||" << std::endl;
    std::cout << "||  Your psyche can't handle it         ||" << std::endl;
    std::cout << "||  and you dropped out of university!  ||" << std::endl;
    std::cout << "||======================================||" << std::endl;
}


//=====PRINT_DAYS_OF_THE_EXAM====
void printExamDays(const GameState &state) {
    std::cout << "!!! WARNING: Exam days are: " << EXAM_1_DAY << ", " << EXAM_2_DAY << ", "
            << EXAM_3_DAY << ", " << state.exam4Day << ", " << EXAM_5_DAY << " !!!" << std::endl;
}


//=====SAVE_GAME_IN_FILE======
void saveGame(const GameState &state) {
    std::ofstream out(SAVE_FILE);
    if (!out) {
        std::cout << "The game failed to save.";
        return;
    }
    out << state.money << " "
            << state.energy << " "
            << state.psychics << " "
            << state.knowledge << " "
            << state.successfulExams << " "
            << state.day << " "
            << state.failedExams << " "
            << state.examNumber << " "
            << state.exam4Day;
    out << std::endl;
    out.close();
    std::cout << "Successfully saved the game." << std::endl;
}


//=====LOAD_GAME_FROM_FILE=====
bool loadGame(GameState &state) {
    std::ifstream in(SAVE_FILE);
    if (!in) {
        std::cout << "The file could not be opened.";
        return false;
    }
    in >> state.money
            >> state.energy
            >> state.psychics
            >> state.knowledge
            >> state.successfulExams
            >> state.day
            >> state.failedExams
            >> state.examNumber
            >> state.exam4Day;
    in.close();
    return true;
}


//=====CHOOSE_GAME_OPTION====
bool beginGame(GameState &state, const int n) {
    if (n == 1) {
        return false;
    }
    if (n == 2) {
        if (!loadGame(state)) {
            std::cout << "Save file not found. Starting new game instead..." << std::endl;
            return false;
        } else {
            std::cout << "Game loaded successfully!" << std::endl;
            return true;
        }
    }
    return false;
}


//============RANDOM_EVENT_FOR_EVERY_DAY=======
void receiveMoney(std::mt19937 &gen, GameState &state) {
    int rand = randomNumber(gen, 1, 30);
    if (rand < 4) {
        state.money += 30;
        std::cout << "Mom and Dad sent money. +30 Money!" << std::endl;
    }
    parameterRestrictions(state);
}

void freeCoffe(std::mt19937 &gen, GameState &state) {
    int rand = randomNumber(gen, 1, 30);
    if (rand < 4) {
        state.psychics += 10;
        std::cout << "Friend treated you to coffee. +10 Psychics!" << std::endl;
    }
    parameterRestrictions(state);
}

void getSick(std::mt19937 &gen, GameState &state) {
    int rand = randomNumber(gen, 1, 30);
    if (rand < 4) {
        state.energy -= 20;
        std::cout << "You got sick. -20 Energy!" << std::endl;
    }
    parameterRestrictions(state);
}

void noElectricity(std::mt19937 &gen, GameState &state) {
    int rand = randomNumber(gen, 1, 30);
    if (rand < 4) {
        state.day++;
        std::cout << "There's no power in the block, you're missing out on the action for the day!" << std::endl;
    }
}


//====ALL_RANDOM_DAY_EVENTS_TOGETHER=====
void randomDayEvents(std::mt19937 &gen, GameState &state) {
    receiveMoney(gen, state);
    freeCoffe(gen, state);
    getSick(gen, state);
    noElectricity(gen, state);
}


//=======SET_THE_INITIAL_VALUES
void initialValue(GameState &state, std::mt19937 &gen) {
    state.day = 1;
    state.money = 0;
    state.energy = 100;
    state.psychics = 100;
    state.knowledge = 0;
    state.successfulExams = 0;
    state.failedExams = 0;
    state.examNumber = 1;
    state.exam4Day = randomNumber(gen, 27, 44);
}


//====START_MENU_INPUT_CHECK====
int handleStartMenu(GameState &state) {
    printBeginGame();
    int option;
    do {
        std::cout << "Choose option 1 or 2: ";
        std::cin >> option;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input." << std::endl;
            continue;
        }
    } while (option != 1 && option != 2);
    bool isLoaded = beginGame(state, option);
    if (isLoaded) {
        return 2;
    } else {
        return 1;
    }
}


//=====DIFFICULTY_MENU_INPUT_CHECK======
void handleDifficultyInput(GameState &state) {
    printDifficultyLevel();
    int level;
    do {
        std::cout << "Choose option 1, 2 or 3: ";
        std::cin >> level;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input." << std::endl;
            continue;
        }
    } while (level < 1 || level > 3);
    difficultyLevel(state, level);
}


//====CHECK_IF_TODAY_IS_AN_EXAM_DAY======
bool isExamDay(const GameState &state) {
    return (state.day == EXAM_1_DAY || state.day == EXAM_2_DAY ||
            state.day == EXAM_3_DAY || state.day == state.exam4Day ||
            state.day == EXAM_5_DAY);
}


//=====DAILY_MENU_OPTIONS====
int getUserAction(const GameState &state) {
    printMenu(state);
    int option;
    bool valid = false;
    do {
        std::cout << "Choose option (1-7) or 8 (if applicable): ";
        std::cin >> option;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input." << std::endl;
            continue;
        }
        if (option == 6 && !isExamDay(state)) {
            std::cout << "Not an exam day! Check the schedule." << std::endl;
            continue;
        }

        if ((option >= 1 && option <= 7) || (option == 8 && state.failedExams > 0)) {
            valid = true;
        } else {
            std::cout << "Invalid option." << std::endl;
        }
    } while (!valid);
    return option;
}

//====TYPE_OF_STUDY_LOGIC=====
void processStudyAction(std::mt19937 &gen, GameState &state) {
    printStudyOptions();
    int studyOption;
    do {
        std::cout << "Choose study type (1-3): ";
        std::cin >> studyOption;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
    } while (studyOption < 1 || studyOption > 3);
    studyOptions(gen, state, studyOption);
}


//========CHEK_IF_THE_GAME_HAS_ENDED=======
bool checkGameEnd(const GameState &state) {
    if (state.psychics < 0) {
        std::cout << "Psychics dropped below 0." << std::endl;
        printLostGame();
        return true;
    }
    if (state.money < 0) {
        std::cout << "Money dropped below 0." << std::endl;
        printLostGame();
        return true;
    }
    if (state.day >= 45 && state.successfulExams < 5) {
        std::cout << "Time is up! Not enough exams passed." << std::endl;
        printLostGame();
        return true;
    }
    if (state.successfulExams == 5) {
        printWinGame();
        return true;
    }
    return false;
}


//====CYCLE_OF_THE_GAME====
void startGame() {
    std::mt19937 gen(std::random_device{}());
    GameState state{};
    initialValue(state, gen);
    if (handleStartMenu(state) == 1) {
        handleDifficultyInput(state);
    }
    while (state.day <= 45) {
        if (state.energy < 0) energyLessThanZero(state);

        printStudentStatus(state);
        randomDayEvents(gen, state);
        printExamDays(state);
        if (isExamDay(state)) {
            std::cout << "Today is exam day! Good luck!" << std::endl;
            goToExam(gen, state);
            state.day++;
            if (checkGameEnd(state)) break;
            continue;
        }
        int action = getUserAction(state);
        if (action == 7) {
            saveGame(state);
            break;
        }
        if (action == 1) {
            processStudyAction(gen, state);
        } else {
            menu(gen, state, action);
        }
        if (checkGameEnd(state)) {
            break;
        }
        state.day++;
    }
}


int main() {
    startGame();
}
