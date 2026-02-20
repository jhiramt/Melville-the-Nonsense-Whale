#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORD_LEN 100

const char * prepPlace(int);

const char * destPlace(int);

const char * adjective(int);

const char * object();

const char * verbing(int);

const char * verb(int);

const char * toVerb();

const char * greeting();

const char * preWritten();

const char * shanty();

const char * creature();

const char * adverb(int);

const char * introduction();

void capitalize(char **);

void capitalize(char ** word) {
    char capword[MAX_WORD_LEN + 1];
    strcpy(capword, *word);
    capword[0] = toupper(*word[0]);
    char * outword = (char*) malloc((MAX_WORD_LEN + 1)*sizeof(char)); //Creates a memory leak, but honestly should not be a problem. If this were more serious than a talking whale I'd figure out where to free it.
    strcpy(outword, capword);
    *word = outword;
    free(outword);
}

void capitalize_copy(const char *input, char *output) {
    if (!input || !output) return;
    strcpy(output, input);
    //output[0] = toupper((unsigned char)input[0]);
    output[0] = toupper(input[0]);
}


void pattern() {
    int option = rand() % 12 + 1; //Choose one of the patterns at random. First number is count of cases.
    switch (option) {
        case 1:
            printf("%s %s %s the %s %s.\n", greeting(), introduction(), verb(0), object(), prepPlace(0));
            break;
        case 2:
            printf("%s %s %s the %s %s!\n", greeting(), introduction(), verb(0), object(), prepPlace(0));
            break;
        case 3:
            printf("%s %s the %s %s.\n", introduction(), verb(0), object(), prepPlace(0));
            break;
        case 4:
            printf("I've seen a %s %s %s.\n", creature(), verbing(0), prepPlace(0));
            break;
        case 5:
            printf("♬..%s..♬\n", shanty());
            break;
        case 6:
            printf("A %s once told me to %s the %s %s.\n", creature(), verb(0), object(), prepPlace(0));
            break;
        case 7:
            printf("%s never let a %s %s yer %s.\n", introduction(), creature(), verb(0), object());
            break;
        case 8:
            printf("A %s? %s? Hornswaggle!\n", creature(), prepPlace(1));
            break;
        case 9:
            printf("The %s %s be %s %s %s!\n", adjective(0), object(), verbing(0), prepPlace(0), adverb(0));
            break;
        case 10:
            printf("%s speaking, there be %ss %s.\n", adverb(1), creature(), prepPlace(0));
            break;
        case 11:
            printf("%s Set sail for %s!", greeting(), destPlace(0));
            break;
        case 12:
            printf("%s there's no one to hear you %s.", prepPlace(1), verb(0));
            break;
    }
}

const char * introduction() {
    static char* introductions[] = {"A word o' wisdom:", "Listen ye here,", "If ye was smart ye'd", "If ye were wise ye'd", "Here be an old sailor's saying:", "Belie' me when I says,", "I'm a tellin ye to"};
    int numIntroductions = sizeof(introductions) / sizeof(*introductions);
    return introductions[rand() % numIntroductions];
}

const char * greeting() { 
    static char* greetings[] = {"Ahoy!", "Ahoy, matey!", "Aye.", "Arr!", "Avast ye!", "Blimey!", "Thar she blows!", "Shiver me timbers!", "Yo ho! ho!" };
    int numGreetings = sizeof(greetings) / sizeof(*greetings);
    return greetings[rand() % numGreetings];
}

const char * preWritten() { // Standalone phrases
    static char* preWrittens[] = {"X marks the spot!", };
    int numPreWrittens = sizeof(preWrittens) / sizeof(*preWrittens);
    return preWrittens[rand() % numPreWrittens];
}

const char * object() { // Normal size objects
    static char* objects[] = {"anchor", "compass", "oar", "harpoon", "cannon", "rope", "ballast", "cutlass", "bottle o' rum", "bottle", "rowboat"};
    int numObjects = sizeof(objects) / sizeof(*objects);
    return objects[rand() % numObjects];
}

const char * prepPlace(int cap) { // Places preceded by an appropriate preposition
    static char* prepPlaces[] = {"under the sea", "in the briny deep", "aboard the ship", "on the poopdeck", "atop the crow's nest", "on the wharf", "amidst the waves", "below deck", "in Davey Jones's locker", "off the coast", "off the coast of Spain", "in the galley", "in the Bermuda triangle", "in the clouds", "in the sea", "around the Northwest passage", "in the heart of the sea"};
    int numPrepPlaces = sizeof(prepPlaces) / sizeof(*prepPlaces);
    char * word = prepPlaces[rand() % numPrepPlaces];
    if (cap == 1) {
        size_t len = strlen(word);
        char buffer[len];
        capitalize_copy(word, buffer);
        word = buffer;
    }
    return word;
}

const char * destPlace(int cap) { // Places formatted as destinations
    static char* destPlaces[] = {"the sea", "the briny deep", "the ship", "the poopdeck", "the crow's nest", "the wharf", "the waves", "Davey Jones's locker", "the coast", "the coast of Spain", "the galley", "the Bermuda triangle", "the clouds", "the Northwest passage", "the Cape"};
    int numDestPlaces = sizeof(destPlaces) / sizeof(*destPlaces);
    char * word = destPlaces[rand() % numDestPlaces];
    if (cap == 1) {
        capitalize(&word);
    }
    return word;
}

const char * creature() { 
    static char* creatures[] = {"mermaid", "crab", "marlin", "whale", "squid", "siren", "leviathan", "tuna", "drowned man"};
    int numCreatures = sizeof(creatures) / sizeof(*creatures);
    return creatures[rand() % numCreatures];
}

const char * verb(int cap) { // Root form of verbs
    static char* verbs[] = {"plunder", "heave", "throw", "stow", "attack", "chase", "find", "harpoon", "maroon", "discover", "drown", "have", "brandish", "dance"};
    int numVerbs = sizeof(verbs) / sizeof(*verbs);
    char * word = verbs[rand() % numVerbs];
    if (cap == 1) {
        capitalize(&word);
    }
    return word;
}

const char * verbing(int cap) { // Active form of verbs
    static char* verbings[] = {"plundering", "heaving", "throwing", "stowing", "attacking", "chasing", "finding", "harpooning", "marooning", "discovering", "drowning", "having", "brandishing", "dancing"};
    int numVerbings = sizeof(verbings) / sizeof(*verbings);
    char * word = verbings[rand() % numVerbings];
    if (cap == 1) {
        capitalize(&word);
    }
    return word;
}

const char * adjective(int cap) {
    static char * adjectives[] = {"blasted", "turbulent", "stormy", "clear", "frothy", "shiny", "fearsome", "ferocious", "lawless", "nautical", "blusterous"};
    int numAdjectives = sizeof(adjectives) / sizeof(*adjectives);
    char * word = adjectives[rand() % numAdjectives];
    if (cap == 1) {
        capitalize(&word);
    }
    return word;
}

const char * adverb(int cap) {
    static char * adverbs[] = {"fitfully", "turbulently", "stormily", "clearly", "fearsomely", "ferociously", "lawlessly", "nautically", "maniacally", "blusterously", "blunderously"};
    int numAdverbs = sizeof(adverbs) / sizeof(*adverbs);
    char * word = adverbs[rand() % numAdverbs];
    if (cap == 1) {
        capitalize(&word);
    }
    return word;
}


const char * shanty() {
    static char* shanties[] = {"Weigh, hey, and up she rises! Weigh hey, and up she rises", "what do we do with a drunken sailor, what do we do with a drunken sailor", "soon may the Wellerman come, to bring us sugar and tea and rum", "up jumps a crab with his crooked legs, saying 'you play the cribbage and I'll stick the pegs'", "the wind it blows from the east nor'east, our ship will scud ten knots at least", "we're homeward bound I hear them say, we're homeward bound with eleven months pay"};
    int numShanties = sizeof(shanties) / sizeof(*shanties);
    return shanties[rand() % numShanties];
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    pattern();
    return 0;
}
