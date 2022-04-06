#include "tile.h"

class chessboard
{
    private:
        int to_move;
        vector<vector<Tile*>> board;
    public:
        vector<string> all_the_moves;
        chessboard();
        ~chessboard();
        void print_chessboard();
        void print_chessboard_2();
        int who_moves();
        vector<string> avail_moves();
        void take_move();
        void play();
        void create_side(int side);
        void play_a_move(string the_move);
        Tile* find_tile(string tile_name);
        void make_move(Tile *old_tile,Tile *new_tile);
        void make_promotion(Tile *old_tile,Tile* new_tile,char new_piece);
        void avail_moves_piece();
        
        void en_passant_add(vector<string> &the_avail_moves);
        //this way is turning out to be very slow, maybe i should find a better way to do this...
        //like instead of deleting and recreating, just temporarily removing the pointers
        // we will see... for now i just want to create a fully working version of chess
        //krikbot is next

        vector<string> avail_move_checker(vector<string> &the_avail_moves);
        void move_revert_short_castle();
        void move_revert_long_castle();
        void move_revert_simple_move(string the_move,int mine_had_moved);
        void move_revert_simple_captures(string the_move,char the_name,int other_had_moved,int mine_had_moved);
        void move_revert_promo(string the_move);
        void move_revert_promo_captures(string the_move,char the_name,int other_had_moved);
        void move_revert_en_passant(string the_move);
        void avail_moves2();

};

