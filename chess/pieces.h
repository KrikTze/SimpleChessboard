#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;


class Tile;

class Piece
{
    private:
        int alive;
        //string square;
        char side;
        int has_moved;
        char name;
    public:
        int get_is_alive();
        //string get_cur_square();
        //Piece(string square,char side,char name);
        Piece(char side,char name);

        //void set_square(string square);
        void set_is_alive();
        char get_side();
        char get_name();
        void set_has_moved();
        void reset_has_moved();
        int get_has_moved();
        virtual void move();
};

class Pawn : public Piece
{
    private:
    public:
        Pawn(char side,char name);
        void move(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves);
        void promote_options_normal(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves,int white_or_black);
        void promote_options_captures(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves,int white_or_black,int new_posy);

};

class Knight : public Piece
{
    private:
    public:
        Knight(char side,char name);
        void move(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves);
        void move_dir(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves,int dir);
};

class Bishop : public Piece
{
    private:
    public:
        Bishop(char side,char name);
        void move(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves);
        void move_dir(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves,int dir);

};

class Rook : public Piece
{
    private:
    public:
        Rook(char side,char name);
        void move(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves);
        void move_dir(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves,int dir);

};

class Queen : public Piece
{
    private:
    public:
        Queen(char side,char name);
        void move(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves);//like a queen
        void move_dir1(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves,int dir);//like a rook
        void move_dir2(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves,int dir);//like a bishop

};

class King : public Piece
{
    private:
    public:
        King(char side,char name);
        void move(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves);
        void move_dir1(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves,int dir);//like a rook 1 square
        void move_dir2(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves,int dir);//like a bishop 1 square
        void castling(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves);
};


//how to find moves and structure of a move.
//after i make the pawns i will make the king
//and then the rest of the pieces,
//and then the stupid rules like an passant and O-O

//how to name the moves
//i am thinking of using the full most complete version possible
// the tile name + the piece name + where it wants to go (i do not think that the x of capturing is required)

//how the pawn moves
//check if it has already moved.
//check if it is a corner pawn.
//check if there is anything ahead of it
//moves by going forward as white +8 / +16
//moves by going backward as black -8/-16
//and captures +7/+9 -7/-9 (check for corner pawns)


//it probably needs typcasting at some point