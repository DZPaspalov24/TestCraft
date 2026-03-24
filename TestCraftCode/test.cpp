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

    for (int i = 0; i <= 20; i++) {
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
{"What is the basic unit of life?", "Cell"},
{"Which organelle is responsible for energy production?", "Mitochondria"},
{"Which organelle contains the cell's genetic material?", "Nucleus"},
{"Which organelle helps in protein synthesis?", "Ribosome"},
{"Which structure controls what enters and exits the cell?", "Cell membrane"},
{"Which organelle is responsible for photosynthesis?", "Chloroplast"},
{"Which organelle stores water and nutrients in plant cells?", "Vacuole"},
{"Which organelle breaks down waste and old cell parts?", "Lysosome"},
{"Which organelle helps in cell division?", "Centrosome"},
{"Which type of cell lacks a nucleus?", "Prokaryotic cell"},
{"What is the jelly-like substance inside the cell?", "Cytoplasm"},
{"Which organelle modifies and packages proteins?", "Golgi apparatus"},
{"Which organelle has a double membrane and produces energy?", "Mitochondria"},
{"Which organelle provides structural support to plant cells?", "Cell wall"},
{"Which process allows substances to move from high to low concentration?", "Diffusion"},
{"Which process uses energy to move substances across a membrane?", "Active transport"},
{"Which organelle contains enzymes for breaking down molecules?", "Lysosome"},
{"Which part of the cell is made of microtubules and microfilaments?", "Cytoskeleton"},
{"Which organelle contains ribosomal RNA?", "Nucleolus"},
{"Which type of cell has a nucleus and membrane-bound organelles?", "Eukaryotic cell"},
{"Which organelle stores and transports proteins?", "Endoplasmic reticulum"},
{"Which organelle helps detoxify chemicals in the cell?", "Smooth endoplasmic reticulum"},
{"Which organelle is involved in photosynthesis in plant cells?", "Chloroplast"},
{"Which organelle helps in packaging materials for transport?", "Golgi apparatus"},
{"Which organelle contains digestive enzymes?", "Lysosome"},
{"Which organelle is a large sac storing water in plant cells?", "Vacuole"},
{"Which cell organelle produces ribosomes?", "Nucleolus"},
{"Which organelle is responsible for energy conversion in animal cells?", "Mitochondria"},
{"Which organelle surrounds the cell and gives protection?", "Cell membrane"},
{"Which organelle is rigid and found only in plant cells?", "Cell wall"}
    };

    runTest(quiz, "Cell");
}

void organismsTest() {
    vector<QA> quiz = {
  {"Which organ pumps blood throughout the body?", "Heart"},
{"Which blood cells fight infections?", "White blood cells"},
{"Which blood cells carry oxygen?", "Red blood cells"},
{"Which organ produces insulin?", "Pancreas"},
{"Which organ stores urine?", "Bladder"},
{"Which organ filters toxins from the blood?", "Liver"},
{"Which vessels carry blood away from the heart?", "Arteries"},
{"Which vessels carry blood back to the heart?", "Veins"},
{"Which organ system controls body responses?", "Nervous system"},
{"Which organ system breaks down food?", "Digestive system"},
{"Which organ system transports nutrients and oxygen?", "Circulatory system"},
{"Which organ system removes waste from the body?", "Excretory system"},
{"Which organ system supports and protects the body?", "Skeletal system"},
{"Which organ system allows movement?", "Muscular system"},
{"Which organ system produces hormones?", "Endocrine system"},
{"Which organ system helps defend against disease?", "Immune system"},
{"Which organ system allows gas exchange?", "Respiratory system"},
{"Which organ stores bile?", "Gallbladder"},
{"Which organ produces digestive enzymes?", "Pancreas"},
{"Which organ absorbs water in digestion?", "Large intestine"},
{"Which organ controls balance and coordination?", "Cerebellum"},
{"Which organ regulates metabolism?", "Thyroid"},
{"Which organ protects the body from infection?", "Skin"},
{"Which organ pumps air in and out of lungs?", "Diaphragm"},
{"Which part of the nervous system connects brain and body?", "Spinal cord"},
{"Which organism part carries oxygen in humans?", "Blood"},
{"Which organisms make their own food?", "Autotrophs"},
{"Which organisms eat other organisms?", "Heterotrophs"},
{"Which organisms break down dead matter?", "Decomposers"},
{"Which organism system coordinates all body functions?", "Nervous system"}
    };

    runTest(quiz, "Organisms");
}

void plantsTest() {
    vector<QA> quiz = {
 {"Which part of the plant absorbs water and minerals?", "Roots"},
{"Which part of the plant supports it and transports nutrients?", "Stem"},
{"Which part of the plant makes food through photosynthesis?", "Leaves"},
{"Which pigment captures sunlight for photosynthesis?", "Chlorophyll"},
{"What process do plants use to make food?", "Photosynthesis"},
{"Which tissue transports water from roots to leaves?", "Xylem"},
{"Which tissue transports food from leaves to other parts?", "Phloem"},
{"Which structure allows gas exchange in leaves?", "Stomata"},
{"Which part protects seeds and helps in dispersal?", "Fruit"},
{"Which plant structure contains seeds?", "Flower"},
{"Which process allows plants to lose water through leaves?", "Transpiration"},
{"Which gas do plants take in for photosynthesis?", "Carbon dioxide"},
{"Which gas do plants release during photosynthesis?", "Oxygen"},
{"Which type of root stores food?", "Taproot"},
{"Which structure prevents water loss in leaves?", "Cuticle"},
{"Which part of a plant grows towards light?", "Shoot"},
{"Which type of reproduction involves seeds?", "Sexual reproduction"},
{"Which type of reproduction involves runners or tubers?", "Asexual reproduction"},
{"Which process moves water from roots to leaves?", "Capillary action"},
{"Which organelle in plant cells performs photosynthesis?", "Chloroplast"},
{"Which tissue strengthens and supports the plant?", "Sclerenchyma"},
{"Which type of plant reproduces using spores?", "Fern"},
{"Which part of the plant is responsible for flowering?", "Shoot apex / Bud"},
{"Which plant hormone promotes stem elongation?", "Auxin"},
{"Which plant hormone promotes fruit ripening?", "Ethylene"},
{"Which plant hormone stimulates seed germination?", "Gibberellin"},
{"Which part anchors the plant in soil?", "Roots"},
{"Which structure transports water in plants?", "Xylem"},
{"Which structure transports sugars in plants?", "Phloem"},
{"Which structure protects developing flower buds?", "Sepal"}
    };

    runTest(quiz, "Plants");
}

void animalsTest() {
    vector<QA> quiz = {
   {"Which organ pumps blood throughout the body?", "Heart"},
{"Which blood cells fight infections?", "White blood cells"},
{"Which blood cells carry oxygen?", "Red blood cells"},
{"Which organ produces digestive enzymes and insulin?", "Pancreas"},
{"Which organ stores urine before excretion?", "Bladder"},
{"Which organ filters toxins from the blood?", "Liver"},
{"Which vessels carry blood away from the heart?", "Arteries"},
{"Which vessels carry blood back to the heart?", "Veins"},
{"Which system controls body responses?", "Nervous system"},
{"Which system breaks down food for energy?", "Digestive system"},
{"Which system transports nutrients and oxygen?", "Circulatory system"},
{"Which system removes waste products from the body?", "Excretory system"},
{"Which system provides support and protection?", "Skeletal system"},
{"Which system allows movement?", "Muscular system"},
{"Which system produces hormones?", "Endocrine system"},
{"Which system helps defend against disease?", "Immune system"},
{"Which system allows gas exchange?", "Respiratory system"},
{"Which organ stores bile?", "Gallbladder"},
{"Which organ absorbs water during digestion?", "Large intestine"},
{"Which organ controls balance and coordination?", "Cerebellum"},
{"Which organ regulates metabolism?", "Thyroid"},
{"Which organ protects the body from infection?", "Skin"},
{"Which organ pumps air in and out of lungs?", "Diaphragm"},
{"Which part of the nervous system connects the brain and body?", "Spinal cord"},
{"Which blood component helps clotting?", "Platelets"},
{"Which type of organism eats plants?", "Herbivore"},
{"Which type of organism eats meat?", "Carnivore"},
{"Which type of organism eats both plants and meat?", "Omnivore"},
{"Which type of reproduction produces genetically identical offspring?", "Asexual reproduction"},
{"Which type of reproduction involves gametes?", "Sexual reproduction"}
    };

    runTest(quiz, "Animals");
}

void humanTest() {
    vector<QA> quiz = {
{"Which organ pumps blood throughout the body?", "Heart"},
{"Which cells carry oxygen in the blood?", "Red blood cells"},
{"Which cells fight infections?", "White blood cells"},
{"Which cells help blood clot?", "Platelets"},
{"Which organ stores urine before excretion?", "Bladder"},
{"Which organ filters toxins from blood?", "Liver"},
{"Which organ produces insulin?", "Pancreas"},
{"Which organ absorbs nutrients from digested food?", "Small intestine"},
{"Which organ regulates breathing?", "Lungs"},
{"Which muscle helps in breathing by contracting and relaxing?", "Diaphragm"},
{"Which organ controls body movements and coordination?", "Brain"},
{"Which organ controls balance and posture?", "Cerebellum"},
{"Which organ transports oxygen to tissues?", "Heart"},
{"Which part of the nervous system connects brain to the body?", "Spinal cord"},
{"Which organ produces bile for digestion?", "Liver"},
{"Which organ stores bile?", "Gallbladder"},
{"Which organ system removes waste from blood?", "Excretory system"},
{"Which organ system transports oxygen, nutrients, and hormones?", "Circulatory system"},
{"Which organ system controls body responses and reflexes?", "Nervous system"},
{"Which organ system breaks down food into nutrients?", "Digestive system"},
{"Which organ system regulates body temperature?", "Integumentary system (Skin)"},
{"Which organ system produces hormones?", "Endocrine system"},
{"Which organ system supports and protects the body?", "Skeletal system"},
{"Which organ system allows voluntary movement?", "Muscular system"},
{"Which organ allows us to hear?", "Ear"},
{"Which organ allows us to see?", "Eye"},
{"Which part of the eye controls the amount of light entering?", "Iris"},
{"Which part of the eye is the opening for light?", "Pupil"},
{"Which organ detects smell?", "Nose"},
{"Which organ detects taste?", "Tongue"}
    };

    runTest(quiz, "Human");
}

void geneticsTest() {
    vector<QA> quiz = {
{"What is the material that carries genetic information?", "DNA"},
{"Which molecule is responsible for protein synthesis?", "RNA"},
{"What is a segment of DNA that codes for a trait?", "Gene"},
{"What are different forms of a gene called?", "Alleles"},
{"Which allele masks the effect of another allele?", "Dominant allele"},
{"Which allele is hidden when a dominant allele is present?", "Recessive allele"},
{"What is the physical appearance of an organism called?", "Phenotype"},
{"What is the genetic makeup of an organism called?", "Genotype"},
{"What is the process by which DNA makes a copy of itself?", "Replication"},
{"Which process produces gametes with half the number of chromosomes?", "Meiosis"},
{"Which process produces body cells with the same number of chromosomes?", "Mitosis"},
{"Who is the father of genetics?", "Gregor Mendel"},
{"What is the principle that alleles segregate during gamete formation?", "Law of Segregation"},
{"What is the principle that different traits are inherited independently?", "Law of Independent Assortment"},
{"What is a cross between two organisms with different traits called?", "Hybrid cross"},
{"What is the result of a cross between heterozygous parents?", "Genotypic and phenotypic ratios"},
{"Which chart shows inheritance of traits in a family?", "Pedigree"},
{"Which term describes an organism with two identical alleles for a trait?", "Homozygous"},
{"Which term describes an organism with two different alleles for a trait?", "Heterozygous"},
{"What is a mutation?", "A change in DNA sequence"},
{"Which type of mutation affects a single gene?", "Point mutation"},
{"Which type of mutation involves changes in chromosome structure?", "Chromosomal mutation"},
{"Which type of inheritance shows both traits expressed in heterozygotes?", "Codominance"},
{"Which inheritance shows blending of traits in heterozygotes?", "Incomplete dominance"},
{"Which inheritance involves multiple alleles for a single trait?", "Multiple alleles"},
{"Which inheritance involves a single gene affecting multiple traits?", "Pleiotropy"},
{"Which inheritance involves multiple genes affecting a single trait?", "Polygenic inheritance"},
{"Which molecule carries amino acids to the ribosome?", "tRNA"},
{"Which molecule forms the backbone of DNA?", "Sugar-phosphate"},
{"Which base pairs always pair together in DNA?", "A-T and G-C"}
    };

    runTest(quiz, "Genetics");
}