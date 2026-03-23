#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>
#include <limits>
#include "menu.h"

using namespace std;

struct QA {
    string question;
    string answer;
};


int runQuiz(vector<QA>& quiz) {
    random_device rd;
    mt19937 g(rd());
    shuffle(quiz.begin(), quiz.end(), g);

    int score = 0;
    string answer;

    for (int i = 0; i <= 20 && i < quiz.size(); i++) {
        system("cls");
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "                           TEST CRAFT - BIOLOGY TEST" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << endl;

        cout << "Question " << i << ": " << quiz[i].question << endl;
        cout << "Answer: ";
        getline(cin, answer);

        if (answer == quiz[i].answer)
            score += 5;
    }

    return score;
}

int getGradeNum(int score) {
    if (score <= 40) return 2;
    else if (score <= 55) return 3;
    else if (score <= 70) return 4;
    else if (score <= 85) return 5;
    else return 6;
}

void printGrade(int score) {
    string gradeText;

    if (score <= 40) gradeText = "Fail, 2.";
    else if (score <= 55) gradeText = "Below Average, 3.";
    else if (score <= 70) gradeText = "Average, 4.";
    else if (score <= 85) gradeText = "Good, 5.";
    else gradeText = "Excellent, 6.";

    system("cls");
    cout << "Your score: " << score << endl;
    cout << "Your grade: " << gradeText << endl;
}

string getName() {
    string name;
    int takenBefore;

    cout << "Have you taken a test before?" << endl;
    cout << "1 - Yes" << endl;
    cout << "2 - No" << endl;
    cout << "Choice: ";
    cin >> takenBefore;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (takenBefore == 1) {
        ifstream file("scores.txt");
        vector<string> names;

        string fileName, testName, testWord;
        int fileScore, fileGrade;

        while (file >> fileName >> testName >> testWord >> fileScore >> fileGrade) {
            if (find(names.begin(), names.end(), fileName) == names.end())
                names.push_back(fileName);
        }
        file.close();

        if (names.empty()) {
            cout << "No previous users found." << endl;
            cout << "Enter your name : ";
            getline(cin, name);
        }
        else {
            cout << "Select your name: " << endl;
            for (int i = 0; i < names.size(); i++)
                cout << i + 1 << " - " << names[i] << endl;

            int choice;
            cout << "Choice: ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            name = names[choice - 1];
        }

        cout << "Welcome back, " << name << "!" << endl;
    }
    else {
        cout << "Enter your name: ";
        getline(cin, name);
        cout << "New student account created: " << name << endl;
    }

    return name;
}


void saveScore(string name, string testName, int score, int gradeNum) {
    ofstream out("scores.txt", ios::app);

    out << name << " " << testName << " test "
        << score << " " << gradeNum << endl;

    out.close();

    system("cls");
    cout << "Saving: " << name << " " << testName
        << " test score: " << score
        << " grade: " << gradeNum << endl;

    cout << "Score saved!" << endl;
}


void returnToMenu() {
    int back;
    cout << "Press 1 to go back to the main menu: ";
    cin >> back;
    while (true) {
        if (back == 1) {
            return;
        }
        else {
            cout << "Invalid input. Chose again: ";
            cin >> back;
        }
    }
}


void runTest(vector<QA> quiz, string testName) {
    int score = runQuiz(quiz);
    printGrade(score);

    string name = getName();
    int grade = getGradeNum(score);

    saveScore(name, testName, score, grade);
    returnToMenu();
}


void cellTest() {
    vector<QA> quiz = {
        {"What is the smallest unit of life?", "Cell"},
        {"Which organ pumps blood throughout the body?", "Heart"},
        {"What structure controls cell activities?", "Nucleus"},
        {"Which blood cells fight infections?", "White blood cells"},
        {"Which blood cells carry oxygen?", "Red blood cells"},
        {"Which organ produces insulin?", "Pancreas"},
        {"What organelle stores water?", "Vacuole"},
        {"Which organ stores urine?", "Bladder"},
        {"Which organ filters toxins?", "Liver"},
        {"What is movement from high to low concentration?", "Diffusion"},
        {"Which vessels carry blood away?", "Arteries"},
        {"Which carry blood back?", "Veins"},
        {"Cells without nucleus?", "Prokaryotes"},
        {"Genetic material?", "DNA"},
        {"Connect muscles to bones?", "Tendons"},
        {"Connect bones?", "Ligaments"},
        {"Plants make food using?", "Photosynthesis"},
        {"Eye part controlling light?", "Iris"},
        {"Another light control part?", "Pupil"},
        {"Microorganism without nucleus?", "Bacteria"},
        {"Muscle separating chest?", "Diaphragm"}
    };

    runTest(quiz, "Cell");
}

void organismsTest() {
    vector<QA> quiz = {
        {"Single-celled organism?", "Unicellular"},
        {"Many-celled organism?", "Multicellular"},
        {"Animal kingdom?", "Animalia"},
        {"Plant kingdom?", "Plantae"},
        {"Fungi kingdom?", "Fungi"},
        {"Bacteria kingdom?", "Monera"},
        {"Identical reproduction?", "Asexual"},
        {"Two-parent reproduction?", "Sexual"},
        {"Basic unit of life?", "Cell"},
        {"Autotroph?", "Producer"},
        {"Heterotroph?", "Consumer"},
        {"Herbivores eat?", "Plants"},
        {"Carnivores eat?", "Animals"},
        {"Omnivores eat?", "Both"},
        {"Decomposer?", "Fungi"},
        {"Fermentation organism?", "Yeast"},
        {"Disease-causing?", "Pathogens"},
        {"Classification study?", "Taxonomy"},
        {"Unicellular example?", "Amoeba"},
        {"Multicellular example?", "Human"},
        {"Photosynthesis organisms?", "Plants"}
    };

    runTest(quiz, "Organisms");
}

void plantsTest() {
    vector<QA> quiz = {
        {"Plant food process?", "Photosynthesis"},
        {"Sunlight pigment?", "Chlorophyll"},
        {"Photosynthesis organelle?", "Chloroplast"},
        {"Outer layer?", "Cellwall"},
        {"Stores water?", "Vacuole"},
        {"Water tissue?", "Xylem"},
        {"Food tissue?", "Phloem"},
        {"Gas exchange?", "Stomata"},
        {"Gas taken in?", "Carbon dioxide"},
        {"Gas released?", "Oxygen"},
        {"Anchors plant?", "Root"},
        {"Absorbs sunlight?", "Leaf"},
        {"Transport structure?", "Stem"},
        {"Seed reproduction?", "Sexual"},
        {"No-seed reproduction?", "Asexual"},
        {"Protects seeds?", "Fruit"},
        {"Non-flowering plants?", "Gymnosperms"},
        {"Flowering plants?", "Angiosperms"},
        {"Green pigment?", "Chlorophyll"},
        {"Water movement?", "Transpiration"},
        {"Non-vascular plants?", "Bryophytes"}
    };

    runTest(quiz, "Plants");
}

void animalsTest() {
    vector<QA> quiz = {
        {"Backbone animals?", "Vertebrates"},
        {"No backbone?", "Invertebrates"},
        {"Egg-laying?", "Oviparous"},
        {"Live birth?", "Viviparous"},
        {"Feathers?", "Birds"},
        {"Fur?", "Mammals"},
        {"Cold-blooded?", "Reptiles"},
        {"Land and water?", "Amphibians"},
        {"Scales animals?", "Fish"},
        {"Milk producers?", "Mammals"},
        {"4-chamber heart?", "Mammals"},
        {"Exoskeleton?", "Arthropods"},
        {"Soft bodies?", "Mollusks"},
        {"Plant eaters?", "Herbivores"},
        {"Meat eaters?", "Carnivores"},
        {"Both eaters?", "Omnivores"},
        {"Fish breathing organ?", "Gills"},
        {"Mammal breathing?", "Lungs"},
        {"Movement system?", "Muscular"},
        {"Transport system?", "Circulatory"},
        {"Hibernate animals?", "Bears"}
    };

    runTest(quiz, "Animals");
}

void humanTest() {
    vector<QA> quiz = {
        {"Blood pump?", "Heart"},
        {"Fight infections?", "White blood cells"},
        {"Carry oxygen?", "Red blood cells"},
        {"Hormone system?", "Endocrine"},
        {"Nerve system?", "Nervous"},
        {"Remove waste?", "Kidneys"},
        {"Digest food?", "Stomach"},
        {"Absorb nutrients?", "Small intestine"},
        {"Produce insulin?", "Pancreas"},
        {"Defense system?", "Immune"},
        {"Support system?", "Skeletal"},
        {"Movement system?", "Muscular"},
        {"Breathing organ?", "Lungs"},
        {"CO2 removal?", "Respiratory"},
        {"Transport system?", "Circulatory"},
        {"Brain system?", "Nervous"},
        {"Produce gametes?", "Reproductive"},
        {"Store urine?", "Bladder"},
        {"Break down food?", "Digestive"},
        {"Filter toxins?", "Liver"},
        {"Thinking brain part?", "Cerebrum"}
    };

    runTest(quiz, "Human");
}

void geneticsTest() {
    vector<QA> quiz = {
        {"Genetic info carrier?", "DNA"},
        {"Protein builder?", "RNA"},
        {"Gene versions?", "Alleles"},
        {"Observable trait?", "Phenotype"},
        {"Genetic makeup?", "Genotype"},
        {"Gamete division?", "Meiosis"},
        {"Identical division?", "Mitosis"},
        {"Reproductive cells?", "Gametes"},
        {"Sex chromosomes?", "Sex chromosomes"},
        {"Other chromosomes?", "Autosomes"},
        {"Mixed alleles?", "Heterozygous"},
        {"Same alleles?", "Homozygous"},
        {"Father of genetics?", "Mendel"},
        {"Mendel organism?", "Pea plant"},
        {"Cross study?", "Hybridization"},
        {"Same chromosome genes?", "Linked"},
        {"Mutation?", "Change"},
        {"Punnett use?", "Prediction"},
        {"One trait?", "Monohybrid"},
        {"Two traits?", "Dihybrid"},
        {"Codominance?", "Both"}
    };

    runTest(quiz, "Genetics");
}