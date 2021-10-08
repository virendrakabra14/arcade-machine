#include <vector>
#include "terrain.cpp"
#include "character_obstacles_coins.cpp"
#include <string>

int main()
{
    initCanvas("Game", wwidth, wheight);

    Terrain t;
    Obstacle o;
    character c;
    Coin c1;

    c.init_Character();

    Rectangle r0(wwidth / 2, wheight - 25, wwidth, 150);
    r0.setColor(COLOR("brown"));
    r0.setFill(true);

    t.initTerrain();

    Text txt(1380, 10, "Score :");

    int i;

    for (i = 0;; i++) {

        Text txt1(1445, 10, to_string(i));
        XEvent event;
        if (checkEvent(event)) {

            if (charFromEvent(event) == 'w') {

                c.jumpup();
                txt1.hide();
                for(int k=0;k<=12;k++) {

                    i++;
                    Text txt1(1455, 10, to_string(i));

                    o.moveObstacles();
                    c1.moveCoin();

                    if (c1.check (c)) {
                        i += 500;
                    }

                    wait(0.05);
                }

                c.fall();

            }
        }

        if(o.check()){ // checks if an obstacle has been hit
            break;
        }

        if (c1.check (c)) { // checks if a coin has been caught
            i += 500;
        }

        int j = randuv(0, 11);

        if (j == 5){
            o.initObstacles();
        }

        j = randuv(0, 20);

        if (j == 10) {
            c1.makeCoin (o);
        }

        o.moveObstacles();
        c1.moveCoin();

        wait(0.05);
    }
    string str = "Final Score : "+to_string(i);
    Text t1(750,150,str);
    getClick();

}
