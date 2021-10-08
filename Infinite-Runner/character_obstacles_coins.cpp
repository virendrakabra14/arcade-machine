# include "obstacles.cpp"
# include "character.cpp"

class Coin {

private:
    int num_coins = 0;
    vector <Circle> coins;
    int radius = 10;

public:
    void makeCoin (Obstacle &o1);
    void moveCoin();
    bool check (character &ch1);

};

void Coin :: makeCoin (Obstacle &o1) {

    srand (time(0));

    int y = randuv (WINDOW_HEIGHT-200, WINDOW_HEIGHT-300);

    if (num_coins == 0) {

        if (o1.num > 0 && !(WINDOW_WIDTH - o1.upper[o1.num-1].getX() > GAP_OBSTACLE_COIN)) return;

        Circle c (WINDOW_WIDTH, y, radius);
        c.setColor (COLOR(255, 215, 0));
        c.setFill (true);

        coins.push_back(c);
        num_coins++;

    }

    else if (num_coins > 0
            && (WINDOW_WIDTH - coins[num_coins-1].getX() > GAP_COINS)) {

        if (o1.num > 0 && !(WINDOW_WIDTH - o1.upper[o1.num-1].getX() > GAP_OBSTACLE_COIN)) return;

        Circle c (WINDOW_WIDTH, y, radius);
        c.setColor (COLOR(255, 215, 0));
        c.setFill (true);

        coins.push_back(c);
        num_coins++;

    }

}

void Coin :: moveCoin () {

    for (int i = 0; i < num_coins; i++) {
        coins[i].move (-20,0);
    }
    if(!(coins.empty()))
    if(coins[0].getX() < 0 && !(coins.empty()))
    {
        coins.erase(coins.begin());
        num_coins--;
    }

}

bool Coin :: check (character &ch1) {

    for (int i = 0; i < num_coins; i++) {

        int x = coins[i].getX();
        int y = coins[i].getY();

        if(x <= 500 && x >= 430 && y <= ch1.r1[25].getY() && y >= ch1.r1[40].getY()) {
            coins.erase(coins.begin()+i);
            num_coins--;
            return true;
        }

    }
    return false;

}
