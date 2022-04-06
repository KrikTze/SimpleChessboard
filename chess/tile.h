#pragma once
#include "pieces.h"

class Tile
{
    private:
        string tile_name;
        int tile_pos;
        int tile_posx;
        int tile_posy;
        Piece *piece_on_tile;
    public:
        Tile(int pos);
        Tile(int posx,int posy);
        ~Tile();
        void move_piece();
        Piece* is_piece();
        void set_piece(Piece *the_piece);
        string get_tile_name();
        void delete_piece();
};

Tile *find_the_tile(string tilename,vector<vector<Tile*>> board);