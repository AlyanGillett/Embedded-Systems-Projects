//Alyan Gillett Arduino Projects
/* This Tinkercad project incorporates an LCD screen to display lyrics while playing a song simultaneously. 
The project utilizes an Arduino board and a LiquidCrystal library for controlling the LCD. 
The lyrics of the song are stored in an array, and each line is displayed on the LCD screen in a loop. 
A timer is also implemented to synchronize the start of the song with the lyrics on the screen. */

//Snippet of Toosie ft Khalid Favorite song
//play the song simultaneously with the lcd screen
//A timer will appear counting down when to start the song in order to line it up with the lyrics on the screen
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

const char* lyrics[] = 
{
  "But nobody's",
  "Gonna make you",

  "change, what",
  "you probably",

  "Don't like",
  "anyway",

  "bout you darlin",
  "So you might",

  "as well",
  "Hmm-mmm",

  "Be somebody",
  "Who can make",

  "you face what",
  "you're guardin",

  "Open up the",
  "gates where your",

  "heart is",
  "And just be",

  "yourself mmmhmmm",
  "Yeah!", 

  "I'm on the stage",
  "right now",

  "singin' your",
  "favorite song",

  "Look in the",
  "crowd,",

  "and you're",
  "nowhere to be",

  "found as they",
  "sing along",

  "I say,",
  "You look good",

  "without",
  "no make-up,",

  "no lashes,",
  "even",

  "better when you",
  "wake up",

  "Oh,oh,oh",
  "I see",

  "the look",
  "on your face,",

  "I see you're",
  "hidin the hate",

  "I see you're",
  "lookin' for",

  "someone to scoop",
  "you right off",

  "of your feet",
  "You want to",

  "ride in the",
  "Wraith",

  "You want to go",
  "out on dates",

  "You want",
  "somebody to come",

  "bring you",
  "flowers",

  "Someone to talk",
  "to for hours",

  "Wash your back",
  "while y'all sit",

  "in the shower",
  "(Yeah)", 

  "Someone to tell",
  "you,",

  "YOU'RE BEAUTIFUL",
  "Someone to tell",

  "you and mean it",
  "Someone to tell",

  "you,",
  "I love you",

  "everyday",
  "and don't",

  "got a reason",
  "You want",

  "someone to",
  "bring you peace",

  "Someone to help",
  "you sleep (Yeah)",

  "Someone to pick",
  "you up when you're",

  "feelin' down,",
  "feelin' lonely",

  "Need somebody",
  "who can make",

  "it better",
  "Somebody who can",

  "open up",
  "those gates",

  "Open up",
  "those gates...",

  "to your heart",
  "Only if",

  "you'll let me <3",
  "The end:"

};


const int delayTimes[] = 
{
  3500,  // Delay after "But nobody's" and "Gonna make you"
  3000,  // Delay after "change, what" and "you probably"
  2000,  // Delay after "Don't like" and "anyway"
  3300,  // Delay after "bout you darlin" and "So you might"
  5200,  // Delay after "as well" and "Hmm-mmm"
  3200,  // Delay after "Be somebody" and "Who can make"
  2000,  // Delay after "you face what" and "you're guardin"
  4000,  // Delay after "Open up the" and "gates where your"
  2000,  // Delay after "heart is" and "And just be"
  6000,  // Delay after "yourself mmmhmmm" and "Yeah"
  2500,  // Delay after "I'm on the stage" and "right now"
  1800,  // Delay after "singin' your" and "favorite song"
  1300,  // Delay after "Look in the" and "crowd,"
  1600,  // Delay after "and you're" and "nowhere to be"
  2000,  // Delay after "found as they" and "sing along"
  1800,  // Delay after "I say," and "You look good"
  1800,  // Delay after "without" and "no make-up,"
  1700,  // Delay after "no lashes," and "even"
  1800,  // Delay after "better when you" and "wake up"
  2000,  // Delay after "Oh,oh,oh" and "I see"
  1000,  // Delay after "the look" and "on your face,"
  1600,  // Delay after "I see you are" and "hidin the hate"
  1400,  // Delay after "I see you are" and "lookin' for"
  900,  // Delay after "someone to scoop" and "you right off"
  900,  // Delay after "of your feet" and "You want to"
  1300,  // Delay after "ride in the" and "Wraith"
  1000,  // Delay after "You want to go" and "out on dates"
  1500,  // Delay after "You want" and "somebody to come"
  1500,  // Delay after "bring you" and "flowers"
  2000,  // Delay after "Someone to talk" and "to for hours"
  1300,  // Delay after "Wash your back" and "while y'all sit"
  1000,  // Delay after "in the shower" and "(Yeah)" 
  
  1000,  // Delay after "Someone to tell" and "you,"
  1800,  // Delay after "YOU'RE BEAUTIFUL" and "Someone to tell"
  1800,  // Delay after "you and mean it" and "Someone to tell"
  1700,  // Delay after "you," and "I love you"
  1500,  // Delay after "everyday" and "and don't"
  1500,  // Delay after "got a reason" and "You want"
  1200,  // Delay after "someone to" and "bring you peace"
  2000,  // Delay after "Someone to help" and "you sleep (Yeah)"
  2300,  // Delay after "Someone to pick" and "you up when you're"
  1800,  // Delay after "feelin' down," and "feelin' lonely"
  2000,  // Delay after "Need somebody" and "who can make"

  3000,  // Delay after "it better" and "Somebody who can"
  3500,  // Delay after "open up" and "those gates"
  3000,  // Delay after "Open up" and "those gates"
  2700,  // Delay after "to your heart" and "Only if"
  10000  // Delay after  "you'll let me <3" and "The end:"

};

const int numLines = sizeof(lyrics) / sizeof(lyrics[0]);


void setup() {
  lcd.begin(16, 2);
  lcd.print("3");
  delay(1000);
  lcd.clear();  // Clear the LCD screen
  lcd.print("2");
  delay(1000);
  lcd.clear();  // Clear the LCD screen
  lcd.print("1");
  delay(1000);

  lcd.clear();  // Clear the LCD screen
}

void loop() {
  int j = 0;
  for (int i = 0; i < numLines; i+=2) {
    lcd.clear();  // Clear the LCD screen
    lcd.setCursor(0, 0);  // Set the cursor to the top-left position
    lcd.print(lyrics[i]);  // Display the current line of lyrics
    lcd.setCursor(0, 1);  // Set the cursor to the top-left position
    lcd.print(lyrics[i+1]);  // Display the next line of lyrics
    delay(delayTimes[j]);  // Delay for the specified time
    j++;
  }
}
