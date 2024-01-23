#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include<unistd.h>
#include <iomanip>

using namespace std;

class Pokemon {
public:
    string name;
    int level;
    int health;
    int maxHealth;
    int attack;
    int defense;
    vector<string> moves;
    Pokemon(){}
    Pokemon(string n, int lvl, int h, int a, int d, vector<string> m) : name(n), level(lvl), health(h), maxHealth(h), attack(a), defense(d), moves(m) {}
    //It initializes the member variables of the Pokemon class with the values provided in the constructor parameters.
    //name(n): Initializes the name variable with the value of the n parameter

       int attackEnemy(Pokemon& enemy, int moveIndex) {
        int damage = (attack * 2) - enemy.defense;
        if (damage < 0)
            damage = 0;

        enemy.health -= damage;
        return damage;
    }
    //damage

    void heal() {
        health = maxHealth;
    }
    //heals pokemon to full health

    void displayStats() {
        cout << name << " (Level " << level << ") | HP: " << health << "/" << maxHealth << endl;
    }
    //displays lvl and hp after every round

    void displayMoves() {
        cout << "Choose a move: " << endl;
        for (int i = 0; i < moves.size(); ++i) {
            cout << i + 1 << ". " << moves[i] << endl;
        }
    }
    //displays the moves
};







class Score : protected Pokemon{
    int score;
public:
    //Score(){}
    Score(){
//        name=poke;
        score=0;
   }
    void get_poke(Pokemon& poke){
        name=poke.name;
        level=poke.level;

    }
    void updateScore(int win){
        if(win==0){
            return;
        }
        else if(win==-1){
            score = score>0?score--:score;
        }
        else if(win==1){
            score+=1;
            if(level<=99 && score%3==0)
                level++;
        }
    }

    void displayScore(){
        cout<<"\nPokemon: "<<name<<endl;
        cout<<"Level: "<<level<<endl;
        cout<<"Score: "<<score<<endl;
        cout<<"[Esc] to continue"<<endl;
        char c;
        do{
            c=_getwch();
        }while(c!=27);
    }
};
Score player1;

void battle(Pokemon& player, Pokemon& enemy) {
    int win=0;
    //player1(player.name);
    while (player.health > 0 && enemy.health > 0) {
        cout << "\nPlayer's Turn - " << player.name << "'s Move" << endl;
        player.displayMoves();
        int choice;
        cin >> choice;

        int damage = player.attackEnemy(enemy, choice - 1);
        cout << "You used " << player.moves[choice - 1] << " and dealt " << damage << " damage to " << enemy.name << "!" << endl;

        if (enemy.health <= 0) {

            cout << enemy.name << " fainted! You win!" << endl;
            win=1;
            player1.updateScore(win);
            break;
        }

        cout << "Enemy's Turn - " << enemy.name << "'s Move" << endl;
        int enemyMove = rand() % enemy.moves.size();
        damage = enemy.attackEnemy(player, enemyMove);
        cout << enemy.name << " used " << enemy.moves[enemyMove] << " and dealt " << damage << " damage to " << player.name << "!" << endl;

        if (player.health <= 0) {
            cout << player.name << " fainted! You lose." << endl;
            win=-1;
            player1.updateScore(win);
            break;
        }

        cout << "Current status: " << endl;
        player.displayStats();
        enemy.displayStats();
        sleep(4);
        system("cls");
    }

    // Heal the player after the battle
    player.heal();
}

int main() {


    srand(static_cast<unsigned>(time(0)));

    vector<Pokemon> availablePokemon{
        {"Pikachu", 5, 100, 25, 10, {"Quick Attack", "Thunder Shock", "Thunder Wave", "Electro Ball"}},
        {"Bulbasaur", 5, 110, 20, 15, {"Vine Whip", "Razor Leaf", "Solar Beam", "Sleep Powder"}},
        {"Charmander", 5, 90, 30, 10, {"Ember", "Flamethrower", "Fire Spin", "Inferno"}},
        {"Squirtle", 5, 95, 22, 18, {"Bubble", "Water Gun", "Hydro Pump", "Aqua Tail"}},
        {"Pidgey", 5, 105, 18, 12, {"Pound", "Body Slam", "Rollout", "Hyper Voice"}},
        {"Caterpie", 5, 98, 24, 14, {"Scratch", "Fury Swipes", "Pay Day", "Dark Pulse"}}
    };
//bvvcvv cuikgvyv
cout<<"\n\n\n\n\n\n\n\n\n\n\n";
cout<<R"(
                                                                    ©2004      Pokemon
                                                                    ©1995-2004 Nintendo
                                                                    ©1995-2004 Creatures Inc.
                                                                    ©1995-2004 GAMEFREAK inc.
                                                                    ©2023-2024 22co10 remake
)";
sleep(3);
system("cls");

cout<<R"(
                                                                                          ,...
                                                                                        .d' ""                           `7MM
                                                                                        dM`                                MM
                                     .P"Ybmmm  ,6"Yb.  `7MMpMMMb.pMMMb.   .gP"Ya       mMMmm  `7Mb,od8  .gP"Ya   ,6"Yb.    MM  ,MP'
                                    :MI  I8   8)   MM    MM    MM    MM  ,M'   Yb       MM      MM' "' ,M'   Yb 8)   MM    MM ;Y
                                     WmmmP"    ,pm9MM    MM    MM    MM  8M""""""       MM      MM     8M""""""  ,pm9MM    MM;Mm
                                    8M        8M   MM    MM    MM    MM  YM.    ,       MM      MM     YM.    , 8M   MM    MM `Mb.
                                     YMMMMMb  `Moo9^Yo..JMML  JMML  JMML. `Mbmmd'     .JMML.  .JMML.    `Mbmmd' `Moo9^Yo..JMML. YA.
                                    6'     dP
                                    Ybmmmd'
        )";

sleep(2);
system("cls");
    system("color 06");        // text colour

    cout<<"\n\n\n\n\n\n\n";
    string text = "22co10 presents\n\n\n";
    int width = 170; // the width of the terminal
    cout << setw((width + text.length()) / 2) << text << endl; //
    sleep(3);
cout<<"\033[1m";    //highlight boldness

cout<<R"(
                                                                              ,'\
                                                _.----.        ____         ,'  _\   ___    ___     ____
                                            _,-'       `.     |    |  /`.   \,-'    |   \  /   |   |    \  |`.
                                            \      __    \    '-.  | /   `.  ___    |    \/    |   '-.   \ |  |
                                             \.    \ \   |  __  |  |/    ,','_  `.  |          | __  |    \|  |
                                               \    \/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |
                                                \     ,-'/  /   \    ,'   | \/ / ,`.|         /  /   \  |     |
                                                 \    \ |   \_/  |   `-.  \    `'  /|  |    ||   \_/  | |\    |
                                                  \    \ \      /       `-.`.___,-' |  |\  /| \      /  | |   |
                                                   \    \ `.__,'|  |`-._    `|      |__| \/ |  `.__,'|  | |   |
                                                    \_.-'       |__|    `-._ |              '-.|     '-.| |   |
                                                                            `'                            '-._|
)";
sleep(2);
cout<<R"(

                          ,,      ,,                                                      ,,                                                      ,,    ,,
                          mm      mm                                     mm             `7MM                                                    `7MM  `7MM
                          MM      MM                                     MM               MM                                                      MM    MM
     .P"Ybmmm  ,pW"Wq.  mmMMmm  mmMMmm   ,6"Yb.       ,p6"bo   ,6"Yb.  mmMMmm   ,p6"bo    MMpMMMb.       .gP"Ya  `7MMpMMMb.pMMMb.       ,6"Yb.    MM    MM
    :MI  I8   6W'   `Wb   MM      MM    8)   MM      6M'  OO  8)   MM    MM    6M'  OO    MM    MM      ,M'   Yb   MM    MM    MM      8)   MM    MM    MM
     WmmmP"   8M     M8   MM      MM     ,pm9MM      8M        ,pm9MM    MM    8M         MM    MM      8M""""""   MM    MM    MM       ,pm9MM    MM    MM
    8M        YA.   ,A9   MM      MM    8M   MM      YM.    , 8M   MM    MM    YM.    ,   MM    MM      YM.    ,   MM    MM    MM      8M   MM    MM    MM
     YMMMMMb   `Ybmd9'    `Mbmo   `Mbmo `Moo9^Yo.     YMbmd'  `Moo9^Yo.  `Mbmo  YMbmd'  .JMML  JMML.     `Mbmmd' .JMML  JMML  JMML.    `Moo9^Yo..JMML..JMML.
    6'     dP
    Ybmmmd'N                                                                     )";
sleep(3);
system("cls");


cout<<R"(                                                                  ;xX$XXXXXXXXXXXXXXXX$$X+:
                                                                     $$xXXXXXXXXXXXXXXXXXXXXXXXXXXxX&;
                                                                 x$XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX:
                                                              +$XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
                                                            $XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX+:::::::+XXXX$;
                                                         :$XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx:::::::::::;xXX$+
                                                        XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx::::::::::::::xXX$:
                                                      +XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX:::::::::::::::;XXXX
                                                     XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx::::::::::::::::xXX$:
                                                   :$XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx::::::::::::::::+XXXx
                                                  :$XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX+::::::::::::::::+XXXX
                                                 :$XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx::::::::::::::::xXXXx
                                                 $XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX:::::::::::::::;XXXX+
                                                XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx::::::::::::::xXXX$
                                               +XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx::::::::::::XXXXX$
                                               $XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx;::::::::xXXXXXX;
                                              ;XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXxxxXXXXXXXXX$
                                              XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX+::xXXXXXXX
                                              $XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX$&&&&&$$XXXXXXXXXXXXXXXXXXXXXXXXXXXXX;;XXXXXXXX:
                                              XXXXXXXXXXXXXXXXXXXXXXXXXXX&XXXXXXXXXXXXX$$XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX$+
                                              &XXXXXXXXXXXXXXXXXXXXXXXX$XXXXXX$$$$$$XXXXX$$XXXXXXXXXXXXXXXXXXXXXXXXXXXXX$$XX+
                                              $XX&XXXXXXXXXXXXXXXXXXX$XXXXX&;:.....::X$XXXX&XXXXXXXXXXXXXXXXXXXXXXXXX&$XXXXX+
                                              $XXXXX$&$XXXXXXXXXXXXX$XXXX$;::::+x+:::::XXXXX$XXXXXXXXXXXXXXXXXX$&$XXXXXXX$$+;
                                              X+$XXXXXXXX$&$XXXXXXXX$XXXX;.:;x:::::x;:::$XXXX$XXXXXXXXXXX$&$XXXXXXXXXX$X:::+
                                              +;:::X&XXXXXXXXXXXXX$&XXXX&::;;::...::+;::;XXXX&$&&$$XXXXXXXXXXXXXX$&+::::..:X
                                               x:::::.:+X$$XXXXXXXXXXXXX&::+;.......;+..;$XXXXXXXXXXXXXXXXX$$x+::.::.....:;+
                                               x;::::.....::.:+$&$$XXXXX$:::$:::::::X:.:XXXXXXXXXX$$&$+:.::..............:x
                                                x::::...........::::&XXXX&::::xXXXx::::xXXXX$;::::::::.................::;;
                                                ;+::::::..........:::$XXXXXX:::::::::;$XXXXXx:::.:................::..:::X
                                                 +;:::::............::&XXXXXXX$$XX$$XXXXXX$+:..........................:X
                                                  x;::::::..........:.:;$XXXXXXXXXXXXXXX$x::.:...:..................:::X
                                                   x;:::::::...........:::x&XXXXXXXXX$$:::...........................:X
                                                    ;x::::::::............::::::;;::::::::......................:::::x
                                                      X::::::::.........:.:...:.....::.....:...:.:...............::+;
                                                       ;x::::::::::...........:............:...................:::X
                                                         x+:::::::::::..:................:.......:...........:::X:
                                                           x+:::::::::::::................................::::$
                                                             ;X:::::::::::::::::::.::..:::::.:.:::.::::::::xx
                                                                xx;:::::::::::::::::::::::::::::::::::::+X:
                                                                   :$+::::::::::::::::::::::::::::::;$+
                                                                       :xXx;::::::::::::::::::;+Xx;
                                                                               ;xX$$&&$$$x+:.                                                           )";
sleep(2);
system("cls");
cout<<R"(                                                                                press any key to continue)";//blinky text
sleep(3);
//accept enter key
//cout<<"/n/n/n/n/n/n/n/n/n/n/n/n/n/n/n/n/n/n/n/n/n";
cout << "0";
    // loop from 1 to 100
    for (int i = 1; i <= 100; i++)
    {
        cout << "";
        // print the current progress
        cout << i<<"%";
        system("cls");
    }
    // print a new line at the end
    cout << endl;


int ls;
        cout<<"\n\n"<<R"(                   VIEW POKEMON ARCHIVE
                        1.BULBASAUR
                        2.SQUIRTLE
                        3.CHARMANDER
                        4.PIDGEY
                        5.CATERPIE
                        6.PIKACHU
                            )";
     do{
        cin>>ls;
        switch(ls)
        {
        case 1:
                system("cls");
                system("color 02");
                cout<<"\033[1m";    //highlight boldness

                cout<<R"(


                                                                            _,.------....___,.' ',.-.
                                                                         ,-'          _,.--"        |
                                                                       ,'         _.-'              .
                                                                      /   ,     ,'                   `
                                                                     .   /     /                     ``.
                                                                     |  |     .                       \.\
                                                           ____      |___._.  |       __               \ `.
                                                         .'    `---""       ``"-.--"'`  \               .  \
                                                        .  ,            __               `              |   .
                                                        `,'         ,-"'  .               \             |    L
                                                       ,'          '    _.'                -._          /    |
                                                      ,`-.    ,".   `--'                      >.      ,'     |
                                                     . .'\'   `-'       __    ,  ,-.         /  `.__.-      ,'
                                                     ||:, .           ,'  ;  /  / \ `        `.    .      .'/
                                                     j|:D  \          `--'  ' ,'_  . .         `.__, \   , /
                                                    / L:_  |                 .  "' :_;                `.'.'
                                                    .    ""'                  """""'                    V
                                                     `.                                 .    `.   _,..  `
                                                       `,_   .    .                _,-'/    .. `,'   __  `
                                                        ) \`._        ___....----"'  ,'   .'  \ |   '  \  .
                                                       /   `. "`-.--"'         _,' ,'     `---' |    `./  |
                                                      .   _  `""'--.._____..--"   ,             '         |
                                                      | ." `. `-.                /-.           /          ,
                                                      | `._.'    `,_            ;  /         ,'          .
                                                     .'          /| `-.        . ,'         ,           ,
                                                     '-.__ __ _,','    '`-..___;-...__   ,.'\ ____.___.'
                                                     `"^--'..'   '-`-^-'"--    `-^-'`.''"""""`.,^.`.--'
                )";
                sleep(1.5);
                cout<<"\n\n\n\n\t\t\t\t\t\t\t\t";
                cout<<R"(       MOVE LIST
                                                                 MOVE           DAMAGE
                                                                 ---------------------
                                                                 Absorb            15
                                                                 Vine whip         15
                                                                 Razor leaf        32
                                                                 Solar beam        45
                         )";
                break;
        case 2:
                system("cls");
                system("color 03");
                cout<<"\033[1m";    //highlight boldness

                cout<<R"(


                                                            _,........__
                                                        ,-'            "`-.
                                                      ,'                   `-.
                                                    ,'                        \
                                                  ,'                           .
                                                  .'\               ,"".       `
                                                 ._.'|             / |  `       \
                                                 |   |            `-.'  ||       `.
                                                 |   |            '-._,'||       | \
                                                 .`.,'             `..,'.'       , |`-.
                                                 l                       .'`.  _/  |   `.
                                                 `-.._'-   ,          _ _'   -" \  .     `
                                            `."""""'-.`-...,---------','         `. `....__.
                                            .'        `"-..___      __,'\          \  \     \
                                            \_ .          |   `""""'    `.           . \     \
                                              `.          |              `.          |  .     L
                                                `.        |`--...________.'.        j   |     |
                                                  `._    .'      |          `.     .|   ,     |
                                                     `--,\       .            `7""' |  ,      |
                                                        ` `      `            /     |  |      |    _,-'"""`-.
                                                         \ `.     .          /      |  '      |  ,'          `.
                                                          \  v.__  .        '       .   \    /| /              \
                                                           \/    `""\"""""""`.       \   \  /.''                |
                                                            `        .        `._ ___,j.  `/ .-       ,---.     |
                                                            ,`-.      \         ."     `.  |/        j     `    |
                                                           /    `.     \       /         \ /         |     /    j
                                                          |       `-.   7-.._ .          |"          '         /
                                                          |          `./_    `|          |            .     _,'
                                                          `.           / `----|          |-............`---'
                                                            \          \      |          |
                                                           ,'           )     `.         |
                                                            7____,,..--'      /          |
                                                                              `---.__,--.'

                )";
                sleep(1.5);
                cout<<"\n\n\n\n\t\t\t\t\t\t\t\t";
                cout<<R"(       MOVE LIST
                                                                 MOVE           DAMAGE
                                                                 ---------------------
                                                                 Tackle            15
                                                                 Bubble            15
                                                                 Water gun         32
                                                                 Hydro pump        45
                         )";
                break;
        case 3:
                system("cls");
                system("color 04");
                cout<<"\033[1m";    //highlight boldness

                cout<<R"(
                                                                     _.--""`-..
                                                                    ,'          `.
                                                                  ,'          __  `.
                                                                 /|          " __   \
                                                                , |           / |.   .
                                                                |,'          !_.'|   |
                                                              ,'             '   |   |
                                                             /              |`--'|   |
                                                            |                `---'   |
                                                             .   ,                   |                       ,".
                                                              ._     '           _'  |                    , ' \ `
                                                          `.. `.`-...___,...---""    |       __,.        ,`"   L,|
                                                          |, `- .`._        _,-,.'   .  __.-'-. /        .   ,    \
                                                        -:..     `. `-..--_.,.<       `"      / `.        `-/ |   .
                                                          `,         """"'     `.              ,'         |   |  ',,
                                                            `.      '            '            /          '    |'. |/
                                                              `.   |              \       _,-'           |       ''
                                                                `._'               \   '"\                .      |
                                                                   |                '     \                `._  ,'
                                                                   |                 '     \                 .'|
                                                                   |                 .      \                | |
                                                                   |                 |       L              ,' |
                                                                   `                 |       |             /   '
                                                                    \                |       |           ,'   /
                                                                  ,' \               |  _.._ ,-..___,..-'    ,'
                                                                 /     .             .      `!             ,j'
                                                                /       `.          /        .           .'/
                                                               .          `.       /         |        _.'.'
                                                                `.          7`'---'          |------"'_.'
                                                               _,.`,_     _'                ,''-----"'
                                                           _,-_    '       `.     .'      ,\
                                                           -" /`.         _,'     | _  _  _.|
                                                            ""--'---"""""'        `' '! |! /
                                                                                    `" " -'

                )";
                sleep(1.5);
                cout<<"\n\n\n\n\t\t\t\t\t\t\t\t";
                    cout<<R"(       MOVE LIST
                                                                     MOVE           DAMAGE
                                                                     ---------------------
                                                                     Scratch           15
                                                                     Ember             15
                                                                     Flamethrower      32
                                                                     Inferno           45
                         )";
                break;
       case 4:
                system("cls");
                system("color 08");
                cout<<"\033[1m";    //highlight boldness

                cout<<R"(


                                                            , _.-','\
                                                          \"\"|\"    `\"\"\"\".
                                                         /'/       __.-'-\"/\
                                                        ','  _,--\"\"      '-._
                                                    _...`...'.\"\"\"\"\"\".\\\"\"
                                                 ,-'          `-.) /  `.  \\\
                                                +---.\"-.    |     `.    .  \\\
                                                     \\  `.  |       \\   |
                                                      `v  ,-j        , .'   |
                                                     .'\\,' /        /,'      -._
                                                    ,____.'        .            `-.
                                                        |         /                `-.
                                                       /          `.                  `-.
                                                      /             `. |                 `.                  _.
                                                     .                `|                 ,-.             _.-\" .
                                                    j                  |                 |  \\         _.'    /
                                                    .                  |               .'    \\     ,-'      /
                                                    |                  |            ,-.\\      \\  ,'      _.-\
                                                    |                . '  `.       |   `      `v'  _,.-\"/\
                                                    ||    \\          |  ` |(`'-`.,.j         \\ `.-'----+---.\
                                                    |'|   |L    \\  | |   `|   \\'              L \\___      /\
                                                    ' L   |`     L | |     `.                 | j   `\"\"\"-'\
                                                       `-'||\\    | ||j       `.       ._    ` '.\
                                                          `\\ '\"`^\"- '          `.       \\    |/|
                                                            `._                  `-.     \\   Y |\
                                                    __,..-\"\"`..`._                  `-._  `\\ `.|
                                                   +.....>+----.' \"\"----.........,--\"\"\" `--.'.'
                                                       ,' _\\  ,..--.-\"' __>---'  |\
                                                      --\"\"  \"'  _.\" }<\"\"          `---\"\"`._
                                                               /...\"  L__.+--   _,......'..'
                                                                 /.-\"\"'/   \\ ,-'
                                                                     .' ,-\"\"'
                                                                    /.-'
                )";
                sleep(1.5);
                cout<<"\n\n\n\n\t\t\t\t\t\t\t\t";
                cout<<R"(       MOVE LIST
                                                                 MOVE           DAMAGE
                                                                 ---------------------
                                                                 Ghust             15
                                                                 Whirlwind         15
                                                                 Wing attack       32
                                                                 Steel wing        45
                         )";
                break;
        case 5:
                system("cls");
                system("color 0A");
                cout<<"\033[1m";    //highlight boldness

                cout<<R"(
                                                                  _,........_
                                                               _.-'    ___    `-._
                                                            ,-'      ,'   \       `.
                                                 _,...    ,'      ,-'     |  ,""":`._.
                                                /     `--+.   _,.'      _.',',|"|  ` \`
                                                \_         `"'     _,-"'  | / `-'   l L\
                                                  `"---.._      ,-"       | l       | | |
                                                      /   `.   |          ' `.     ,' ; |
                                                     j     |   |           `._`"""' ,'  |__
                                                     |      `--'____          `----'    .' `.
                                                     |    _,-"""    `-.                 |    \
                                                     l   /             `.               F     l
                                                      `./     __..._     `.           ,'      |
                                                        |  ,-"      `.    | ._     _.'        |
                                                        . j           \   j   /`"""      __   |          ,"`.
                                                         `|           | _,.__ |        ,'  `. |          |   |
                                                          `-._       /-'     `L       .     , '          |   |
                                                              F-...-'          `      |    , /           |   |
                                                              |            ,----.     `...' /            |   |
                                                              .--.        j      l        ,'             |   j
                                                             j    L       |      |'-...--<               .  /
                                                             `     |       . __,,_    ..  |               \/
                                                              `-..'.._  __,-'     \  |  |/`._           ,'`
                                                                  |   ""       .--`. `--,  ,-`..____..,'   |
                                                                   L          /     \ _.  |   | \  .-.\    j
                                                                  .'._        l     .\    `---' |  |  || ,'
                                                                   .  `..____,-.._.'  `._       |  `--;"I'
                                                                    `--"' `.            ,`-..._/__,.-1,'
                                                                            `-.__  __,.'     ,' ,' _-'
                                                                                 `'...___..`'--^--'
                )";
                sleep(1.5);
                cout<<"\n\n\n\n\t\t\t\t\t\t\t\t";
                    cout<<R"(       MOVE LIST
                                                                     MOVE           DAMAGE
                                                                     ---------------------
                                                                     String shot       15
                                                                     Tackle            15
                                                                     Poison sting      32
                                                                     Bug bite          45
                         )";
                break;
        case 6:
                system("cls");
                system("color 0E");
                cout<<"\033[1m";    //highlight boldness

                cout<<R"(
                                             quu..__
                                             $$$b  `---.__
                                              "$$b        `--.                          ___.---uuudP
                                               `$$b           `.__.------.__     __.---'      $$$$"              .
                                                 "$b          -'            `-.-'            $$$"              .'|
                                                   ".                                       d$"             _.'  |
                                                     `.   /                              ..."             .'     |
                                                       `./                           ..::-'            _.'       |
                                                        /                         .:::-'            .-'         .'
                                                       :                          ::''\          _.'            |
                                                      .' .-.             .-.           `.      .'               |
                                                      : /'$$|           .@"$\           `.   .'              _.-'
                                                     .'|$u$$|          |$$,$$|           |  <            _.-'
                                                     | `:$$:'          :$$$$$:           `.  `.       .-'
                                                     :                  `"--'             |    `-.     \
                                                    :##.       ==             .###.       `.      `.    `\
                                                    |##:                      :###:        |        >     >
                                                    |#'     `..'`..'          `###'        x:      /     /
                                                     \                                   xXX|     /    ./
                                                      \                                xXXX'|    /   ./
                                                      /`-.                                  `.  /   /
                                                     :    `-  ...........,                   | /  .'
                                                     |         ``:::::::'       .            |<    `.
                                                     |             ```          |           x| \ `.:``.
                                                     |                         .'    /'   xXX|  `:`M`M':.
                                                     |    |                    ;    /:' xXXX'|  -'MMMMM:'
                                                     `.  .'                   :    /:'       |-'MMMM.-'
                                                      |  |                   .'   /'        .'MMM.-'
                                                      `'`'                   :  ,'          |MMM<
                                                        |                     `'            |tbap\
                                                         \                                  :MM.-'
                                                          \                 |              .''
                                                           \.               `.            /
                                                            /     .:::::::.. :           /
                                                           |     .:::::::::::`.         /
                                                           |   .:::------------\       /
                                                          /   .''               >::'  /
                                                          `',:                 :    .'
                                                                               `:.:'
                )";
                cout<<"\n\n\n\n\t\t\t\t\t\t\t\t";
                cout<<R"(       MOVE LIST
                                                                 MOVE           DAMAGE
                                                                 ---------------------
                                                                 Quick Attack      15
                                                                 Thundershock      15
                                                                 Thunder Bolt      32
                                                                 Electro Ball      45
                         )";
                sleep(1.5);
                break;

        case 7:
                break;
        default :
                system("cls");
                system("color 0A");
                cout<<"\033[1m";    //highlight boldness
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t";
                cout<<"INVALID CHOICE DONT BE GAE!!";

        }
        cout<<"\n\n\n";
        cout<<"wanna view a different pokemon? ";
        cout<<"Enter a value:";
       }while(ls!=7);






system("cls");





    int playerChoice;
    cout<<R"(                                                                       ______CHOOSE YOUR POKEMON_______

                                                                                 1.PIKACHU
                                                                                 2.BULBASAUR
                                                                                 3.CHARMANDER
                                                                                 4.SQUIRTLE
                                                                                 5.PIDGEY
                                                                                 6.CATERPIE
                                                                             )";


    cin >> playerChoice;
    system("cls");

    if (playerChoice < 1 || playerChoice > 6) {
        cout << "Invalid choice. Defaulting to Pikachu." << endl;
        playerChoice = 1;
    }

    Pokemon player = availablePokemon[playerChoice - 1];
    availablePokemon.erase(availablePokemon.begin() + playerChoice - 1);

    while (!availablePokemon.empty()) {
        int enemyChoice = rand() % availablePokemon.size();
        Pokemon enemy = availablePokemon[enemyChoice];

        cout << "\nA wild " << enemy.name << " appeared!" << endl;
        cout << "You sent out " << player.name << "!" << endl;
        sleep(2);
        system("cls");
        player1.get_poke(player);
        battle(player, enemy);

        // Remove defeated enemy from the available Pokemon list
        availablePokemon.erase(availablePokemon.begin() + enemyChoice);

        //Display score
        player1.displayScore();
        // Ask the player if they want to continue battling
        char cont;
            cout << "Do you want to continue battling? (y/n): ";
            cin>>cont;
            system("cls");
        if (cont == 'y' && cont == 'Y') {
            cout << "Thanks for playing!" << endl;
            break;
        }
    }

    return 0;
}
