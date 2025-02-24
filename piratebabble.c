#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Seed for random number generation
    
    char *greetings[] = {"Ahoy,", "Arr,", "Avast ye!", "Blimey,", "Thar she blows!", "Shiver me timbers!", };
    char *nouns[] = {"anchor", "compass", "ship", "sea", "sky", "harpoon", "deck", "anchor", "storm", "cannon", "briney deep", "Davy Jones' locker", "scallywag", "scurvy", "poop deck", "rope" };
    char *activeVerbs[] = {"sailing", "navigating", "roamin'", "drifting", "lollygagging", "swashbuckling", "harpooning", "plundering"};
    char *adjectives[] = {"beautiful", "turbulent", "stormy", "clear", "peaceful", "frothy", "adrift", "ferocious", "fearsome", "lawless", "nautical" };
    
    int numGreetings = sizeof(greetings) / sizeof(greetings[0]);
    int numNouns = sizeof(nouns) / sizeof(nouns[0]);
    int numVerbs = sizeof(activeVerbs) / sizeof(activeVerbs[0]);
    int numAdjectives = sizeof(adjectives) / sizeof(adjectives[0]);
    
    printf("'%s the %s %s be %s in the %s %sly!'",
           greetings[rand() % numGreetings], adjectives[rand() % numAdjectives], nouns[rand() % numNouns], activeVerbs[rand() % numVerbs], nouns[rand() % numNouns], adjectives[rand() % numAdjectives]);

    return 0;
}
