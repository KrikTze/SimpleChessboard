#include "tile.h"

Tile::Tile(int pos)
{
    this->piece_on_tile=NULL;
    this->tile_pos=pos;
    int div=0;
    int mod=0;
    string temp_name;
    mod=pos%8;
    div=pos/8;
    char a='a';
    a=a+div;
    temp_name=a+to_string(mod+1);    
    this->tile_name=temp_name;
}

Tile::Tile(int posx,int posy)
{
    this->piece_on_tile=NULL;
    this->tile_posx=posx;
    this->tile_posy=posy;
    int div=0;
    int mod=0;
    string temp_name;
    mod=posx;
    div=posy;
    char a='a';
    a=a+div;
    temp_name=a+to_string(mod+1);    
    this->tile_name=temp_name;
    cout << temp_name << endl;
}

Tile::~Tile()
{
    if(piece_on_tile!=NULL)
    {
        delete piece_on_tile;
    }
}

void Tile::delete_piece()
{
    if(piece_on_tile!=NULL)
    {
        delete piece_on_tile;
    }
    piece_on_tile=NULL;
}

string Tile::get_tile_name()
{
    return this->tile_name;
}

Piece* Tile::is_piece()
{
    if(this->piece_on_tile!=NULL)
    {
        return this->piece_on_tile;
    }
    else
    {
        return NULL;
    }
}

void Tile::move_piece()
{
    if(this->piece_on_tile!=NULL)
    {
        this->piece_on_tile=NULL;
    }
}

void Tile::set_piece(Piece *the_piece)
{//could be a capture, for now lets ignore this occassion
    /*
    string Piece_namw;
    if(this->piece_on_tile!=NULL)
    {
        delete (Pawn*)this->piece_on_tile;
    } */
    this->piece_on_tile=the_piece;

}

Tile* find_the_tile(string tile_name,vector<vector<Tile*>> board)
{
    Tile *temp_tile;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(board[i][j]->get_tile_name()==tile_name)
            {
                temp_tile=board[i][j];
            }
        }
    }
    return temp_tile;
}
