#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>
#include "menu.h"
using namespace std;

struct QA {
    string question;
    string answer;
};

void cellTest() {
    vector<QA> quiz = {
        {"What is the smallest unit of life?", "Cell"},
        {"Which organ pumps blood throughout the body?", "Heart"},
        {"What structure controls cell activities?", "Nucleus"},
        {"Which blood cells are responsible for fighting infections?", "White blood cells"},
        {"Which blood cells carry oxygen?", "Red blood cells"},
		{"Which organ produces Insulin?", "Pancreas"},
        {"What organelle stores water and nutrients?", "Vacuole"},
		{"Which organ stores urine?", "Bladder"},
        {"Which organ filters toxins from the blood?", "Liver"},
        {"What is the movement of particles from high to low concentration called?", "Diffusion"},
        {"Which vessels carry blood away from the heart?", "Arteries"},
		{"Which vessels carry blood back to the heart?", "Veins"},
        {"What type of cells do not have a nucleus?", "Prokaryotes"},
        {"What is the genetic material in cells called?", "DNA"},
		{"What connects muscles to bones?", "Tendons"},
		{"What connects bones to other bones?", "Ligaments"},
        {"What process allows plants to make food using sunlight?", "Photosynthesis"},
		{"Which part of eyes controls the amount of light entering?", "Iris"},
		{"Which part of eyes controls the amount of light entering?", "Pupil"},
        {"What microorganism type lacks a nucleus?", "Bacteria"},
		{"Which muscle seperates the chest from the abdomen?", "Diaphragm"},
		{"What is the outer layer of the skin called?", "Epidermis"},
		{"What is the largest internal organ?", "Liver"},
		{"How many bones are in the human body?", "206"},
        {"What structure contains DNA in eukaryotic cells?", "Nucleus"},
		{"What is the tube that carries air to the lungs?", "Trachea"},
		{"Which cell transmits nerve signals?", "Neuron"},
		{"Which part of the neuron receives signals?", "Dendrites"},
		{"Wich part of the neuron sends signals?", "Axon"},
        {"Which hormone is released during stress?", "Cortisol"},
    };

    random_device rd;
    mt19937 g(rd());
    shuffle(quiz.begin(), quiz.end(), g);

    string answer;
    int score = 0;

    for (int i = 0; i <= 20; i++) {
        system("cls"); 
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "                           TEST CRAFT-BIOLOGY TESTS                          " << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << " " << endl;
        cout << "Question " << i <<": " << quiz[i].question << endl;
        cout << "Answer: ";
        getline(cin, answer);

        if (answer == quiz[i].answer) {
            score += 5;
        }
    }

    string grade;
    int back = 0;
    if (score <= 40) {
        grade = "Fail, 2.";
    }
    else if (score >= 41 && score <= 55) {
        grade = "Below Average, 3.";
    }
    else if (score >= 56 && score <= 70) {
        grade = "Average, 4.";
    }
    else if (score >= 71 && score <= 85) {
        grade = "Good, 5.";
    }
    else {
        grade = "Excellent, 6.";
    }
    system("cls");
    cout << "Your score: " << score << endl;
    cout << "Your grade is: " << grade << endl;
    cout << endl;
    cout << "Press 1 to go to the main menu: ";
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




void organismsTest() {
    vector<QA> quiz = {
      {"What is a single-celled organism called?", "Unicellular"},
    {"What is an organism made of many cells?", "Multicellular"},
    {"Which kingdom includes all animals?", "Animalia"},
    {"Which kingdom includes all plants?", "Plantae"},
    {"Which kingdom includes fungi?", "Fungi"},
    {"Which kingdom includes bacteria?", "Monera"},
    {"Which kingdom includes protists?", "Protista"},
    {"What type of reproduction produces genetically identical offspring?", "Asexual"},
    {"What type of reproduction involves two parents?", "Sexual"},
    {"What is the basic unit of structure in all living organisms?", "Cell"},
    {"What is an autotroph?", "Producer"},
    {"What is a heterotroph?", "Consumer"},
    {"What do herbivores eat?", "Plants"},
    {"What do carnivores eat?", "Animals"},
    {"What do omnivores eat?", "Both"},
    {"What is a producer in an ecosystem?", "Organism"},
    {"What is a consumer in an ecosystem?", "Organism"},
    {"What is a decomposer?", "Fungi"},
    {"Which microorganism can be used in fermentation?", "Yeast"},
    {"Which microorganisms can cause diseases?", "Pathogens"},
    {"What is the study of organisms and their classification?", "Taxonomy"},
    {"What is the term for organisms that live in extreme environments?", "Extremophiles"},
    {"Which microorganisms are prokaryotic?", "Bacteria"},
    {"Which microorganisms are eukaryotic?", "Protists"},
    {"What is the difference between prokaryotic and eukaryotic cells?", "Nucleus"},
    {"What is an example of a unicellular organism?", "Amoeba"},
    {"What is an example of a multicellular organism?", "Human"},
    {"Which organisms make their own food using sunlight?", "Plants"},
    {"Which organisms consume other organisms for energy?", "Animals"},
    {"What term describes organisms living together and interacting?", "Community"}
    };

    random_device rd;
    mt19937 g(rd());
    shuffle(quiz.begin(), quiz.end(), g);

    string answer;
    int score = 0;

    for (int i = 0; i <= 20; i++) {
        system("cls");
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "                           TEST CRAFT-BIOLOGY TESTS                          " << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << " " << endl;
        cout << "Question " << i << ": " << quiz[i].question << endl;
        cout << "Answer: ";
        getline(cin, answer);

        if (answer == quiz[i].answer) {
            score += 5;
        }
    }

    string grade;
    int back = 0;
    if (score <= 40) {
        grade = "Fail, 2.";
    }
    else if (score >= 41 && score <= 55) {
        grade = "Below Average, 3.";
    }
    else if (score >= 56 && score <= 70) {
        grade = "Average, 4.";
    }
    else if (score >= 71 && score <= 85) {
        grade = "Good, 5.";
    }
    else {
        grade = "Excellent, 6.";
    }
    system("cls");
    cout << "Your score: " << score << endl;
    cout << "Your grade is: " << grade << endl;
    cout << endl;
    cout << "Press 1 to go to the main menu: ";
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

void plantsTest() {
    vector<QA> quiz = {
      {"What process do plants use to make their own food?", "Photosynthesis"},
    {"Which pigment captures sunlight in plants?", "Chlorophyll"},
    {"What organelle in plant cells carries out photosynthesis?", "Chloroplast"},
    {"What is the rigid outer layer of plant cells called?", "Cellwall"},
    {"What stores water and nutrients in plant cells?", "Vacuole"},
    {"What tissue carries water from roots to leaves?", "Xylem"},
    {"What tissue carries food from leaves to other parts?", "Phloem"},
    {"What is the main site of gas exchange in leaves?", "Stomata"},
    {"What gas do plants take in for photosynthesis?", "Carbon dioxide"},
    {"What gas is released by plants during photosynthesis?", "Oxygen"},
    {"Which part of the plant anchors it to the soil?", "Root"},
    {"Which part of the plant absorbs sunlight?", "Leaf"},
    {"Which part of the plant supports it and transports nutrients?", "Stem"},
    {"What type of reproduction involves seeds?", "Sexual"},
    {"What is reproduction without seeds called?", "Asexual"},
    {"Which structures contain pollen in flowering plants?", "Anther"},
    {"Which part of the flower receives pollen?", "Stigma"},
    {"What is the female reproductive part of a flower?", "Pistil"},
    {"What is the male reproductive part of a flower?", "Stamen"},
    {"What protects developing seeds?", "Fruit"},
    {"What type of plants do not produce flowers?", "Gymnosperms"},
    {"What type of plants produce flowers?", "Angiosperms"},
    {"Which plant tissue helps in growth at tips?", "Meristem"},
    {"What is the green pigment in leaves?", "Chlorophyll"},
    {"Which process allows water to move up from roots?", "Transpiration"},
    {"What term describes non-vascular plants?", "Bryophytes"},
    {"What term describes vascular plants?", "Tracheophytes"},
    {"Which plant stores food in roots, like carrots?", "Taproot"},
    {"What structure helps climbing plants attach?", "Tendrils"},
    {"What is the reproductive unit of a fern?", "Spore"},
    {"Which hormone helps plants grow towards light?", "Auxin"}
    };

    random_device rd;
    mt19937 g(rd());
    shuffle(quiz.begin(), quiz.end(), g);

    string answer;
    int score = 0;

    for (int i = 0; i <= 20; i++) {
        system("cls");
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "                           TEST CRAFT-BIOLOGY TESTS                          " << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << " " << endl;
        cout << "Question " << i << ": " << quiz[i].question << endl;
        cout << "Answer: ";
        getline(cin, answer);

        if (answer == quiz[i].answer) {
            score += 5;
        }
    }

    string grade;
    int back = 0;
    if (score <= 40) {
        grade = "Fail, 2.";
    }
    else if (score >= 41 && score <= 55) {
        grade = "Below Average, 3.";
    }
    else if (score >= 56 && score <= 70) {
        grade = "Average, 4.";
    }
    else if (score >= 71 && score <= 85) {
        grade = "Good, 5.";
    }
    else {
        grade = "Excellent, 6.";
    }
    system("cls");
    cout << "Your score: " << score << endl;
    cout << "Your grade is: " << grade << endl;
    cout << endl;
    cout << "Press 1 to go to the main menu: ";
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

void animalsTest() {
    vector<QA> quiz = {
    {"What is the term for animals with a backbone?", "Vertebrates"},
    {"What is the term for animals without a backbone?", "Invertebrates"},
    {"Which vertebrates lay eggs?", "Oviparous"},
    {"Which vertebrates give live birth?", "Viviparous"},
    {"Which group of animals has feathers?", "Birds"},
    {"Which group of animals has fur or hair?", "Mammals"},
    {"Which animals are cold-blooded?", "Reptiles"},
    {"Which animals can live both in water and on land?", "Amphibians"},
    {"Which animals have scales and lay eggs in water?", "Fish"},
    {"Which animals produce milk for their young?", "Mammals"},
    {"Which animals have a three-chambered heart?", "Amphibians"},
    {"Which animals have a four-chambered heart?", "Mammals"},
    {"Which invertebrates have exoskeletons?", "Arthropods"},
    {"Which invertebrates have soft bodies and sometimes shells?", "Mollusks"},
    {"What is the term for animals that eat only plants?", "Herbivores"},
    {"What is the term for animals that eat only other animals?", "Carnivores"},
    {"What is the term for animals that eat both plants and animals?", "Omnivores"},
    {"Which organ in fish helps with breathing?", "Gills"},
    {"Which organ in mammals helps with breathing?", "Lungs"},
    {"Which body system controls movement?", "Muscular"},
    {"Which body system controls communication and coordination?", "Nervous"},
    {"Which body system transports blood and nutrients?", "Circulatory"},
    {"Which body system removes waste?", "Excretory"},
    {"Which body system protects against disease?", "Immune"},
    {"Which animals migrate to find food or breeding grounds?", "Birds"},
    {"Which animals hibernate during winter?", "Bears"},
    {"Which animals use camouflage to hide?", "Chameleons"},
    {"Which animals are warm-blooded?", "Mammals"},
    {"Which animals lay eggs with hard shells?", "Birds"},
    {"Which animals have segmented bodies and jointed limbs?", "Arthropods"},
    {"Which animals are known for metamorphosis?", "Insects"}
    };

    random_device rd;
    mt19937 g(rd());
    shuffle(quiz.begin(), quiz.end(), g);

    string answer;
    int score = 0;

    for (int i = 0; i <= 20; i++) {
        system("cls");
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "                           TEST CRAFT-BIOLOGY TESTS                          " << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << " " << endl;
        cout << "Question " << i << ": " << quiz[i].question << endl;
        cout << "Answer: ";
        getline(cin, answer);

        if (answer == quiz[i].answer) {
            score += 5;
        }
    }

    string grade;
    int back = 0;
    if (score <= 40) {
        grade = "Fail, 2.";
    }
    else if (score >= 41 && score <= 55) {
        grade = "Below Average, 3.";
    }
    else if (score >= 56 && score <= 70) {
        grade = "Average, 4.";
    }
    else if (score >= 71 && score <= 85) {
        grade = "Good, 5.";
    }
    else {
        grade = "Excellent, 6.";
    }
    system("cls");
    cout << "Your score: " << score << endl;
    cout << "Your grade is: " << grade << endl;
    cout << endl;
    cout << "Press 1 to go to the main menu: ";
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

void humanTest() {
    vector<QA> quiz = {
{"Which organ pumps blood throughout the body?", "Heart"},
    {"Which blood cells fight infections?", "White blood cells"},
    {"Which blood cells carry oxygen?", "Red blood cells"},
    {"Which system controls body functions using hormones?", "Endocrine"},
    {"Which system controls body functions using nerves?", "Nervous"},
    {"Which organ removes waste from the blood?", "Kidneys"},
    {"Which organ digests food?", "Stomach"},
    {"Which organ absorbs nutrients?", "Small intestine"},
    {"Which organ stores bile?", "Gallbladder"},
    {"Which organ produces insulin?", "Pancreas"},
    {"Which system defends the body against pathogens?", "Immune"},
    {"Which system supports the body and protects organs?", "Skeletal"},
    {"Which system moves the body?", "Muscular"},
    {"Which organ helps you breathe?", "Lungs"},
    {"Which system removes carbon dioxide?", "Respiratory"},
    {"Which system transports blood and nutrients?", "Circulatory"},
    {"Which gland produces sweat?", "Sweat glands"},
    {"Which system includes the brain and spinal cord?", "Nervous"},
    {"Which system produces gametes?", "Reproductive"},
    {"Which organ stores urine?", "Bladder"},
    {"Which system breaks down food?", "Digestive"},
    {"Which organ produces digestive enzymes?", "Pancreas"},
    {"Which system regulates water and salt balance?", "Excretory"},
    {"Which organ filters toxins from the blood?", "Liver"},
    {"Which organ stores oxygen for emergencies?", "Spleen"},
    {"Which system senses stimuli?", "Sensory"},
    {"Which part of the brain controls balance?", "Cerebellum"},
    {"Which part of the brain controls thinking?", "Cerebrum"},
    {"Which part of the brain controls involuntary actions?", "Medulla"},
    {"Which system regulates hormones?", "Endocrine"},
    {"Which organ connects muscles to bones?", "Tendons"}
    };

    random_device rd;
    mt19937 g(rd());
    shuffle(quiz.begin(), quiz.end(), g);

    string answer;
    int score = 0;

    for (int i = 0; i <= 20; i++) {
        system("cls");
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "                           TEST CRAFT-BIOLOGY TESTS                          " << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << " " << endl;
        cout << "Question " << i << ": " << quiz[i].question << endl;
        cout << "Answer: ";
        getline(cin, answer);

        if (answer == quiz[i].answer) {
            score += 5;
        }
    }

    string grade;
    int back = 0;
    if (score <= 40) {
        grade = "Fail, 2.";
    }
    else if (score >= 41 && score <= 55) {
        grade = "Below Average, 3.";
    }
    else if (score >= 56 && score <= 70) {
        grade = "Average, 4.";
    }
    else if (score >= 71 && score <= 85) {
        grade = "Good, 5.";
    }
    else {
        grade = "Excellent, 6.";
    }
    system("cls");
    cout << "Your score: " << score << endl;
    cout << "Your grade is: " << grade << endl;
    cout << endl;
    cout << "Press 1 to go to the main menu: ";
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

void geneticsTest() {
    vector<QA> quiz = {
    {"What carries genetic information?", "DNA"},
    {"What is the protein-building molecule?", "RNA"},
    {"What are different versions of a gene called?", "Alleles"},
    {"What is the observable trait of an organism?", "Phenotype"},
    {"What is the genetic makeup of an organism?", "Genotype"},
    {"What type of cell division produces gametes?", "Meiosis"},
    {"What type of cell division produces identical cells?", "Mitosis"},
    {"What are reproductive cells called?", "Gametes"},
    {"Which chromosomes determine sex?", "Sex chromosomes"},
    {"Which chromosomes determine other traits?", "Autosomes"},
    {"What is the term for a dominant and recessive allele together?", "Heterozygous"},
    {"What is the term for two identical alleles?", "Homozygous"},
    {"Who is the father of genetics?", "Mendel"},
    {"What organism did Mendel study?", "Pea plant"},
    {"What is a cross between parents to study traits?", "Hybridization"},
    {"What is the term for genes located on the same chromosome?", "Linked"},
    {"What is a mutation?", "Change"},
    {"What is a Punnett square used for?", "Prediction"},
    {"What is inheritance of one trait called?", "Monohybrid"},
    {"Inheritance of two traits?", "Dihybrid"},
    {"What is codominance?", "Both"},
    {"What is incomplete dominance?", "Blending"},
    {"What is a pedigree chart used for?", "Family"},
    {"What is a carrier?", "Heterozygous"},
    {"What is a genotype ratio?", "Ratio"},
    {"What is a phenotype ratio?", "Ratio"},
    {"Which molecule is double-stranded?", "DNA"},
    {"Which molecule is single-stranded?", "RNA"},
    {"What is translation in genetics?", "Protein"},
    {"What is transcription in genetics?", "RNA"}
    };

    random_device rd;
    mt19937 g(rd());
    shuffle(quiz.begin(), quiz.end(), g);

    string answer;
    int score = 0;

    for (int i = 0; i <= 20; i++) {
        system("cls");
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "                           TEST CRAFT-BIOLOGY TESTS                          " << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << " " << endl;
        cout << "Question " << i << ": " << quiz[i].question << endl;
        cout << "Answer: ";
        getline(cin, answer);

        if (answer == quiz[i].answer) {
            score += 5;
        }
    }

    string grade;
    int back = 0;
    if (score <= 40) {
        grade = "Fail, 2.";
    }
    else if (score >= 41 && score <= 55) {
        grade = "Below Average, 3.";
    }
    else if (score >= 56 && score <= 70) {
        grade = "Average, 4.";
    }
    else if (score >= 71 && score <= 85) {
        grade = "Good, 5.";
    }
    else {
        grade = "Excellent, 6.";
    }
    system("cls");
    cout << "Your score: " << score << endl;
    cout << "Your grade is: " << grade << endl;
    cout << endl;
    cout << "Press 1 to go to the main menu: ";
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