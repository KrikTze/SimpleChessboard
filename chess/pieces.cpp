
#include "pieces.h"
#include "tile.h"

string create_move_name(string tile_name,char name,string new_tile_name)
{
    string move_name=tile_name+name+new_tile_name;
    return move_name;
}

string create_move_name_captures(string tile_name,char name, string new_tile_name)
{
    string move_name=tile_name+name+"x"+new_tile_name;
    return move_name;
}

string create_move_promotion(string tile_name,char name, string new_tile_name,char new_piece)
{
    string move_name=tile_name+name+new_tile_name+"="+new_piece;
    return move_name;
}

string create_move_promotion_captures(string tile_name,char name, string new_tile_name,char new_piece)
{
    string move_name=tile_name+name+"x"+new_tile_name+"="+new_piece;
    return move_name;
}



Piece::Piece(char side,char name)
{
    this->side=side;
    alive=1;
    //this->square=square;
    this->has_moved=0;
    this->name=name;
}

void Piece::reset_has_moved()
{
    this->has_moved=0;
}

void Piece::move()
{
    return;
}

void Piece::set_has_moved()
{
    this->has_moved=1;
}

int Piece::get_has_moved()
{
    return this->has_moved;
}

int Piece::get_is_alive()
{
    return this->alive;
}

/*string Piece::get_cur_square()
{
    return this->square;
} */

char Piece::get_side()
{
    return this->side;
}

/*void Piece::set_square(string square)
{
    this->square=square;
} */
void Piece::set_is_alive()
{
    this->alive=0;
}

char Piece::get_name()
{
    return this->name;
}

Pawn::Pawn(char side,char name):Piece(side,name)
{
    //this->name=name;
    //Piece::Piece(square);
}

void Pawn::promote_options_normal(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves,int white_or_black)
{
    char new_piece[4];
    if(white_or_black>0)
    {
        new_piece[0]='N';
        new_piece[0]='B';
        new_piece[0]='R';
        new_piece[0]='Q';
    }
    else
    {
        new_piece[0]='2';
        new_piece[0]='3';
        new_piece[0]='4';
        new_piece[0]='5';

    }
    the_avail_moves.push_back(create_move_promotion(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+white_or_black][posy]->get_tile_name(),new_piece[0]));
    //cout << create_move_promotion(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+white_or_black][posy]->get_tile_name(),new_piece[0]) << endl;

    the_avail_moves.push_back(create_move_promotion(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+white_or_black][posy]->get_tile_name(),new_piece[1]));
    //cout << create_move_promotion(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+white_or_black][posy]->get_tile_name(),new_piece[1]) << endl;

    the_avail_moves.push_back(create_move_promotion(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+white_or_black][posy]->get_tile_name(),new_piece[2]));
    //cout << create_move_promotion(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+white_or_black][posy]->get_tile_name(),new_piece[2]) << endl;

    the_avail_moves.push_back(create_move_promotion(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+white_or_black][posy]->get_tile_name(),new_piece[3]));
    //cout << create_move_promotion(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+white_or_black][posy]->get_tile_name(),new_piece[3]) << endl;


}

void Pawn::promote_options_captures(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves,int white_or_black,int new_posy)
{
    char new_piece[4];
    if(white_or_black>0)
    {
        new_piece[0]='N';
        new_piece[1]='B';
        new_piece[2]='R';
        new_piece[3]='Q';
    }
    else
    {
        new_piece[0]='2';
        new_piece[1]='3';
        new_piece[2]='4';
        new_piece[3]='5';

    }
    the_avail_moves.push_back(create_move_promotion_captures(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+white_or_black][new_posy]->get_tile_name(),new_piece[0]));
    //cout << create_move_promotion_captures(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+white_or_black][posy]->get_tile_name(),new_piece[0]) << endl;

    the_avail_moves.push_back(create_move_promotion_captures(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+white_or_black][new_posy]->get_tile_name(),new_piece[1]));
    //cout << create_move_promotion_captures(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+white_or_black][new_posy]->get_tile_name(),new_piece[1]) << endl;

    the_avail_moves.push_back(create_move_promotion_captures(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+white_or_black][new_posy]->get_tile_name(),new_piece[2]));
    //cout << create_move_promotion_captures(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+white_or_black][new_posy]->get_tile_name(),new_piece[2]) << endl;

    the_avail_moves.push_back(create_move_promotion_captures(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+white_or_black][new_posy]->get_tile_name(),new_piece[3]));
    //cout << create_move_promotion_captures(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+white_or_black][new_posy]->get_tile_name(),new_piece[3]) << endl;


}


void Pawn::move(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves)
{
    int white_or_black;
    if(get_name()=='P')
    {
        white_or_black=1;
    }
    else
    {
        white_or_black=-1;
    }
    int corner_flag1=0; //a file
    int corner_flag2=0; //h file
    int promo=0;
    if(posy==0)
    {
        corner_flag1=1;
    }
    if(posy==7)
    {
        corner_flag2=1;
    }

    if(posx+white_or_black>0 && posx+white_or_black<7)
    {
        //basic move
        if(board[posx+white_or_black][posy]->is_piece()==NULL)
        {
            //cout << create_move_name(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+white_or_black][posy]->get_tile_name()) << endl;
            the_avail_moves.push_back(create_move_name(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+white_or_black][posy]->get_tile_name()));
        }
        //double step
        //since i am going to use constraint satifaction anyway we will see about this
        if(this->get_has_moved()==0)
        {
            if(board[posx+white_or_black][posy]->is_piece()==NULL)
            {
                if(board[posx+2*white_or_black][posy]->is_piece()==NULL)
                {
                    //cout << create_move_name(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+2*white_or_black][posy]->get_tile_name()) << endl;
                    the_avail_moves.push_back(create_move_name(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+2*white_or_black][posy]->get_tile_name()));
                }
            }
        }
        //captures
        if(corner_flag1)
        {
            if(board[posx+white_or_black][posy+1]->is_piece()!=NULL)
            {
                if(board[posx][posy]->is_piece()->get_side()!=board[posx+white_or_black][posy+1]->is_piece()->get_side())
                {
                    the_avail_moves.push_back(create_move_name_captures(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+white_or_black][posy+1]->get_tile_name()));
                    //cout << create_move_name_captures(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+white_or_black][posy+1]->get_tile_name()) << endl;
                }
            }
        }
        else if(corner_flag2)
        {
            if(board[posx+white_or_black][posy-1]->is_piece()!=NULL)
            {
                if(board[posx][posy]->is_piece()->get_side()!=board[posx+white_or_black][posy-1]->is_piece()->get_side())
                {
                    the_avail_moves.push_back(create_move_name_captures(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+white_or_black][posy-1]->get_tile_name()));
                    //cout << create_move_name_captures(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+white_or_black][posy-1]->get_tile_name()) << endl;
                }
            }
        }
        else
        {
            if(board[posx+white_or_black][posy+1]->is_piece()!=NULL)
            {
                if(board[posx][posy]->is_piece()->get_side()!=board[posx+white_or_black][posy+1]->is_piece()->get_side())
                {
                    the_avail_moves.push_back(create_move_name_captures(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+white_or_black][posy+1]->get_tile_name()));
                    //cout << create_move_name_captures(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+white_or_black][posy+1]->get_tile_name()) << endl;
                }
            }
            if(board[posx+white_or_black][posy-1]->is_piece()!=NULL)
            {
                if(board[posx][posy]->is_piece()->get_side()!=board[posx+white_or_black][posy-1]->is_piece()->get_side())
                {
                    the_avail_moves.push_back(create_move_name_captures(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+white_or_black][posy-1]->get_tile_name()));
                    //cout << create_move_name_captures(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+white_or_black][posy-1]->get_tile_name()) << endl;
                }
            }
        }
        
        // here i should also create a special occasion for promotion
        // a tweak must be done to the previous code
        // accounting for when a pawn is on x7 or x2 respectively
        
        // so a simple solution is . let it go till the x2 or x7
        // and then almost copy paste the code for the last step
        // using 4times more options(for each piece)
        // and the = sign , i think i am comfortable with this. at least for now.
        
    }
    else if(posx+white_or_black==0 || posx+white_or_black==7)
    {
        //
        if(board[posx+white_or_black][posy]->is_piece()==NULL)
        {   //maybe create the options function to decrease the number of copy paste 
            promote_options_normal(board,posx,posy,the_avail_moves,white_or_black);        
        
        }

        if(corner_flag1)
        {
            if(board[posx+white_or_black][posy+1]->is_piece()!=NULL)
            {
                if(board[posx][posy]->is_piece()->get_side()!=board[posx+white_or_black][posy+1]->is_piece()->get_side())
                {
                    promote_options_captures(board,posx,posy,the_avail_moves,white_or_black,posy+1);
                }
            }
        }
        else if(corner_flag2)
        {
            if(board[posx+white_or_black][posy-1]->is_piece()!=NULL)
            {
                if(board[posx][posy]->is_piece()->get_side()!=board[posx+white_or_black][posy-1]->is_piece()->get_side())
                {
                    promote_options_captures(board,posx,posy,the_avail_moves,white_or_black,posy-1);
                }
            }
        }
        else
        {
            if(board[posx+white_or_black][posy+1]->is_piece()!=NULL)
            {
                if(board[posx][posy]->is_piece()->get_side()!=board[posx+white_or_black][posy+1]->is_piece()->get_side())
                {
                    promote_options_captures(board,posx,posy,the_avail_moves,white_or_black,posy+1);
                }
            }
            if(board[posx+white_or_black][posy-1]->is_piece()!=NULL)
            {
                if(board[posx][posy]->is_piece()->get_side()!=board[posx+white_or_black][posy-1]->is_piece()->get_side())
                {
                    promote_options_captures(board,posx,posy,the_avail_moves,white_or_black,posy-1);
                }
            }
        }

    }

}


Knight::Knight(char side,char name):Piece(side,name)
{
    //this->name=name;
    //Piece::Piece(square);
}
void Knight::move_dir(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves,int dir)
{
    int x_move;
    int y_move;

    if(dir==0)
    {
        x_move=1;
        y_move=-2;
    }
    else if(dir==1)
    {
        x_move=2;
        y_move=-1;
    }

    else if(dir==2)
    {
        x_move=2;
        y_move=1;
    }
    else if(dir==3)
    {
        x_move=1;
        y_move=2;
    }
    else if(dir==4)
    {
        x_move=-1;
        y_move=2;
    }
    else if(dir==5)
    {
        x_move=-2;
        y_move=1;
    }
    else if(dir==6)
    {
        x_move=-2;
        y_move=-1;
    }
    else
    {
        x_move=-1;
        y_move=-2;
    }

    if((posx+x_move)<8 && (posx+x_move)>-1)
    {
        if((posy+y_move)>-1 && (posy+y_move)<8)
        {
            if(board[posx+x_move][posy+y_move]->is_piece()==NULL)
            {
                //cout << create_move_name(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()) << endl;
                the_avail_moves.push_back(create_move_name(board[posx][posy]->get_tile_name(),this->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()));

            }
            else if(board[posx+x_move][posy+y_move]->is_piece()->get_side()!=board[posx][posy]->is_piece()->get_side())
            {
                the_avail_moves.push_back(create_move_name_captures(board[posx][posy]->get_tile_name(),board[posx][posy]->is_piece()->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()));
                //cout << create_move_name_captures(board[posx][posy]->get_tile_name(),board[posx][posy]->is_piece()->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()) << endl;            
            }
        }
    }

}
void Knight::move(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves)
{
    //suppose its in the centre of the board
    //and look its available moves
    //clockwise
    // x+1 y-2

    //clockwise
    // x+1 y-2
    move_dir(board,posx,posy,the_avail_moves,0);
    // x+2 y-1
    move_dir(board,posx,posy,the_avail_moves,1);

    // x+2 y+1
    move_dir(board,posx,posy,the_avail_moves,2);

    // x+1 y+2
    move_dir(board,posx,posy,the_avail_moves,3);

    // x-1 y+2
    move_dir(board,posx,posy,the_avail_moves,4);

    // x-2 y+1
    move_dir(board,posx,posy,the_avail_moves,5);
    // x-2 y-1
    move_dir(board,posx,posy,the_avail_moves,6);
    // x-1 y-2
    move_dir(board,posx,posy,the_avail_moves,7);
}


Bishop::Bishop(char side,char name):Piece(side,name)
{
    //this->name=name;
    //Piece::Piece(square);
}

void Bishop::move_dir(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves,int dir)
{
    int x_move;
    int original_x_move;
    int y_move;
    int original_y_move;
    int edge1;
    int edge2;
    //the difference here is that two fold
    //a both x and y move have to participate
    //b for each direction i have to check 2 potential edges!
    if(dir==0)
    {
        x_move=1;
        y_move=1;
        original_x_move=1;
        original_y_move=1;
        edge1=8;
        edge2=8;
    }
    else if(dir==1)
    {
        x_move=1;
        y_move=-1;
        original_x_move=1;
        original_y_move=-1;
        edge1=8;
        edge2=-1;
    }
    else if(dir==2)
    {
        x_move=-1;
        y_move=1;
        original_x_move=-1;
        original_y_move=1;
        edge1=-1;
        edge2=8;
    }
    else
    {
        x_move=-1;
        y_move=-1;
        original_x_move=-1;
        original_y_move=-1;
        edge1=-1;
        edge2=-1;
    }
    while(posx+x_move!=edge1 && posy+y_move!=edge2) 
    {
        if(board[posx+x_move][posy+y_move]->is_piece()==NULL)
        {
            the_avail_moves.push_back(create_move_name(board[posx][posy]->get_tile_name(),board[posx][posy]->is_piece()->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()));
            //cout << create_move_name(board[posx][posy]->get_tile_name(),board[posx][posy]->is_piece()->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()) << endl;
        }
        else
        {
            if(board[posx+x_move][posy+y_move]->is_piece()->get_side()!=board[posx][posy]->is_piece()->get_side())
            {
                the_avail_moves.push_back(create_move_name_captures(board[posx][posy]->get_tile_name(),board[posx][posy]->is_piece()->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()));
                //cout << create_move_name_captures(board[posx][posy]->get_tile_name(),board[posx][posy]->is_piece()->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()) << endl;            
            }
            break;
        }
        //update
        x_move=x_move+original_x_move;
        y_move=y_move+original_y_move;
    }

}

void Bishop::move(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves)
{
    //looking from white's prespective

    //up&right
    move_dir(board,posx,posy,the_avail_moves,0);
    //up&left
    move_dir(board,posx,posy,the_avail_moves,1);
    //down&right
    move_dir(board,posx,posy,the_avail_moves,2);
    //down&left
    move_dir(board,posx,posy,the_avail_moves,3);


}

Rook::Rook(char side,char name):Piece(side,name)
{
    //this->name=name;
    //Piece::Piece(square);
}

void Rook::move_dir(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves,int dir)
{
    //what if i use != to go there? not bad
    int x_move;
    int original_x_move;
    int y_move;
    int original_y_move;
    int edge1;
    int edge2;
    if(dir==0)
    {
        x_move=1;
        original_x_move=1;
        y_move=0;
        original_y_move=0;
        edge1=8;
        edge2=1000;
    }
    else if(dir==1)
    {
        x_move=-1;
        original_x_move=-1;
        y_move=0;
        original_y_move=0;
        edge1=-1;
        edge2=1000;
    }
    else if(dir==2)
    {
        x_move=0;
        original_x_move=0;
        y_move=1;
        original_y_move=1;
        edge1=1000;
        edge2=8;
    }
    else
    {
        x_move=0;
        original_x_move=0;
        y_move=-1;
        original_y_move=-1;
        edge1=1000;
        edge2=-1;
    }
    //the one coursor wont move and the other will do its job properly
    while(posx+x_move!=edge1 && posy+y_move!=edge2) 
    {
        if(board[posx+x_move][posy+y_move]->is_piece()==NULL)
        {
            the_avail_moves.push_back(create_move_name(board[posx][posy]->get_tile_name(),board[posx][posy]->is_piece()->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()));
            //cout << create_move_name(board[posx][posy]->get_tile_name(),board[posx][posy]->is_piece()->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()) << endl;
        }
        else
        {
            if(board[posx+x_move][posy+y_move]->is_piece()->get_side()!=board[posx][posy]->is_piece()->get_side())
            {
                the_avail_moves.push_back(create_move_name_captures(board[posx][posy]->get_tile_name(),board[posx][posy]->is_piece()->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()));
                //cout << create_move_name_captures(board[posx][posy]->get_tile_name(),board[posx][posy]->is_piece()->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()) << endl;            
            }
            break;
        }
        //update
        x_move=x_move+original_x_move;
        y_move=y_move+original_y_move;
    }

}

void Rook::move(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves)
{
    //all the tiles in front
    move_dir(board,posx,posy,the_avail_moves,0);
    //all the tiles behind
    move_dir(board,posx,posy,the_avail_moves,1);

    //all the tiles left
    move_dir(board,posx,posy,the_avail_moves,2);

    //all the tiles right
    move_dir(board,posx,posy,the_avail_moves,3);

}

Queen::Queen(char side,char name):Piece(side,name)
{
    //this->name=name;
    //Piece::Piece(square);
}
void Queen::move_dir1(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves,int dir) // like a rook
{
    //what if i use != to go there? not bad
    int x_move;
    int original_x_move;
    int y_move;
    int original_y_move;
    int edge1;
    int edge2;
    if(dir==0)
    {
        x_move=1;
        original_x_move=1;
        y_move=0;
        original_y_move=0;
        edge1=8;
        edge2=1000;
    }
    else if(dir==1)
    {
        x_move=-1;
        original_x_move=-1;
        y_move=0;
        original_y_move=0;
        edge1=-1;
        edge2=1000;
    }
    else if(dir==2)
    {
        x_move=0;
        original_x_move=0;
        y_move=1;
        original_y_move=1;
        edge1=1000;
        edge2=8;
    }
    else
    {
        x_move=0;
        original_x_move=0;
        y_move=-1;
        original_y_move=-1;
        edge1=1000;
        edge2=-1;
    }
    //the one coursor wont move and the other will do its job properly
    while(posx+x_move!=edge1 && posy+y_move!=edge2) 
    {
        if(board[posx+x_move][posy+y_move]->is_piece()==NULL)
        {
            the_avail_moves.push_back(create_move_name(board[posx][posy]->get_tile_name(),board[posx][posy]->is_piece()->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()));
            //cout << create_move_name(board[posx][posy]->get_tile_name(),board[posx][posy]->is_piece()->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()) << endl;
        }
        else
        {
            if(board[posx+x_move][posy+y_move]->is_piece()->get_side()!=board[posx][posy]->is_piece()->get_side())
            {
                the_avail_moves.push_back(create_move_name_captures(board[posx][posy]->get_tile_name(),board[posx][posy]->is_piece()->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()));
                //cout << create_move_name_captures(board[posx][posy]->get_tile_name(),board[posx][posy]->is_piece()->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()) << endl;            
            }
            break;
        }
        //update
        x_move=x_move+original_x_move;
        y_move=y_move+original_y_move;
    }

}

void Queen::move_dir2(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves,int dir) // like a bishop
{
    int x_move;
    int original_x_move;
    int y_move;
    int original_y_move;
    int edge1;
    int edge2;
    //the difference here is that two fold
    //a both x and y move have to participate
    //b for each direction i have to check 2 potential edges!
    if(dir==0)
    {
        x_move=1;
        y_move=1;
        original_x_move=1;
        original_y_move=1;
        edge1=8;
        edge2=8;
    }
    else if(dir==1)
    {
        x_move=1;
        y_move=-1;
        original_x_move=1;
        original_y_move=-1;
        edge1=8;
        edge2=-1;
    }
    else if(dir==2)
    {
        x_move=-1;
        y_move=1;
        original_x_move=-1;
        original_y_move=1;
        edge1=-1;
        edge2=8;
    }
    else
    {
        x_move=-1;
        y_move=-1;
        original_x_move=-1;
        original_y_move=-1;
        edge1=-1;
        edge2=-1;
    }
    while(posx+x_move!=edge1 && posy+y_move!=edge2) 
    {
        if(board[posx+x_move][posy+y_move]->is_piece()==NULL)
        {
            the_avail_moves.push_back(create_move_name(board[posx][posy]->get_tile_name(),board[posx][posy]->is_piece()->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()));
            //cout << create_move_name(board[posx][posy]->get_tile_name(),board[posx][posy]->is_piece()->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()) << endl;
        }
        else
        {
            if(board[posx+x_move][posy+y_move]->is_piece()->get_side()!=board[posx][posy]->is_piece()->get_side())
            {
                the_avail_moves.push_back(create_move_name_captures(board[posx][posy]->get_tile_name(),board[posx][posy]->is_piece()->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()));
                //cout << create_move_name_captures(board[posx][posy]->get_tile_name(),board[posx][posy]->is_piece()->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()) << endl;            
            }
            break;
        }
        //update
        x_move=x_move+original_x_move;
        y_move=y_move+original_y_move;
    }
}

void Queen::move(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves)
{
    //from white's prespective

    //all the tiles in front
    move_dir1(board,posx,posy,the_avail_moves,0);
    //all the tiles behind
    move_dir1(board,posx,posy,the_avail_moves,1);

    //all the tiles left
    move_dir1(board,posx,posy,the_avail_moves,2);

    //all the tiles right
    move_dir1(board,posx,posy,the_avail_moves,3);

    //up&right
    move_dir2(board,posx,posy,the_avail_moves,0);
    //up&left
    move_dir2(board,posx,posy,the_avail_moves,1);
    //down&right
    move_dir2(board,posx,posy,the_avail_moves,2);
    //down&left
    move_dir2(board,posx,posy,the_avail_moves,3);


}



King::King(char side,char name):Piece(side,name)
{
    //this->name=name;
    //Piece::Piece(square);
}

void King::move_dir1(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves,int dir) // like a rook
{
    //what if i use != to go there? not bad
    int x_move;
    int original_x_move;
    int y_move;
    int original_y_move;
    int edge1;
    int edge2;
    if(dir==0)
    {
        x_move=1;
        original_x_move=1;
        y_move=0;
        original_y_move=0;
        edge1=8;
        edge2=1000;
    }
    else if(dir==1)
    {
        x_move=-1;
        original_x_move=-1;
        y_move=0;
        original_y_move=0;
        edge1=-1;
        edge2=1000;
    }
    else if(dir==2)
    {
        x_move=0;
        original_x_move=0;
        y_move=1;
        original_y_move=1;
        edge1=1000;
        edge2=8;
    }
    else
    {
        x_move=0;
        original_x_move=0;
        y_move=-1;
        original_y_move=-1;
        edge1=1000;
        edge2=-1;
    }
    //the one coursor wont move and the other will do its job properly
    while(posx+x_move!=edge1 && posy+y_move!=edge2) 
    {
        if(board[posx+x_move][posy+y_move]->is_piece()==NULL)
        {
            the_avail_moves.push_back(create_move_name(board[posx][posy]->get_tile_name(),board[posx][posy]->is_piece()->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()));
            //cout << create_move_name(board[posx][posy]->get_tile_name(),board[posx][posy]->is_piece()->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()) << endl;
        }
        else
        {
            if(board[posx+x_move][posy+y_move]->is_piece()->get_side()!=board[posx][posy]->is_piece()->get_side())
            {
                the_avail_moves.push_back(create_move_name_captures(board[posx][posy]->get_tile_name(),board[posx][posy]->is_piece()->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()));
                //cout << create_move_name_captures(board[posx][posy]->get_tile_name(),board[posx][posy]->is_piece()->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()) << endl;            
            }
            break;
        }
        //update
        x_move=x_move+original_x_move;
        y_move=y_move+original_y_move;
        break;
    }

}

void King::move_dir2(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves,int dir) // like a bishop
{
    int x_move;
    int original_x_move;
    int y_move;
    int original_y_move;
    int edge1;
    int edge2;
    //the difference here is that two fold
    //a both x and y move have to participate
    //b for each direction i have to check 2 potential edges!
    if(dir==0)
    {
        x_move=1;
        y_move=1;
        original_x_move=1;
        original_y_move=1;
        edge1=8;
        edge2=8;
    }
    else if(dir==1)
    {
        x_move=1;
        y_move=-1;
        original_x_move=1;
        original_y_move=-1;
        edge1=8;
        edge2=-1;
    }
    else if(dir==2)
    {
        x_move=-1;
        y_move=1;
        original_x_move=-1;
        original_y_move=1;
        edge1=-1;
        edge2=8;
    }
    else
    {
        x_move=-1;
        y_move=-1;
        original_x_move=-1;
        original_y_move=-1;
        edge1=-1;
        edge2=-1;
    }
    while(posx+x_move!=edge1 && posy+y_move!=edge2) 
    {
        if(board[posx+x_move][posy+y_move]->is_piece()==NULL)
        {
            the_avail_moves.push_back(create_move_name(board[posx][posy]->get_tile_name(),board[posx][posy]->is_piece()->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()));
            //cout << create_move_name(board[posx][posy]->get_tile_name(),board[posx][posy]->is_piece()->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()) << endl;
        }
        else
        {
            if(board[posx+x_move][posy+y_move]->is_piece()->get_side()!=board[posx][posy]->is_piece()->get_side())
            {
                the_avail_moves.push_back(create_move_name_captures(board[posx][posy]->get_tile_name(),board[posx][posy]->is_piece()->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()));
                //cout << create_move_name_captures(board[posx][posy]->get_tile_name(),board[posx][posy]->is_piece()->get_name(),board[posx+x_move][posy+y_move]->get_tile_name()) << endl;            
            }
            break;
        }
        //update
        x_move=x_move+original_x_move;
        y_move=y_move+original_y_move;
        break;
    }
}

void King::castling(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves)
{
    //if the king hasnt moved
    if(this->get_has_moved()==0)
    {
        //for small castling
        if(board[posx][posy+1]->is_piece()==NULL)
        {
            if(board[posx][posy+2]->is_piece()==NULL)
            {
                //this means that the rook has not moved
                if(board[posx][posy+3]->is_piece()->get_has_moved()==0)
                {
                    //cout << "O-O" << endl;
                    the_avail_moves.push_back("O-O");
                }
            }
        }

        if(board[posx][posy-1]->is_piece()==NULL && board[posx][posy-2]->is_piece()==NULL)
        {
            if(board[posx][posy-3]->is_piece()==NULL)
            {
                //this means that the rook has not moved
                if(board[posx][posy-4]->is_piece()->get_has_moved()==0)
                {
                    //cout << "O-O-O" << endl;
                    the_avail_moves.push_back("O-O-O");
                }
            }
        }
    }
}

void King::move(vector<vector<Tile*>> board,int posx,int posy,vector<string> &the_avail_moves)
{
    //from white's prespective

    //all the tiles in front
    move_dir1(board,posx,posy,the_avail_moves,0);
    //all the tiles behind
    move_dir1(board,posx,posy,the_avail_moves,1);

    //all the tiles left
    move_dir1(board,posx,posy,the_avail_moves,2);

    //all the tiles right
    move_dir1(board,posx,posy,the_avail_moves,3);

    //up&right
    move_dir2(board,posx,posy,the_avail_moves,0);
    //up&left
    move_dir2(board,posx,posy,the_avail_moves,1);
    //down&right
    move_dir2(board,posx,posy,the_avail_moves,2);
    //down&left
    move_dir2(board,posx,posy,the_avail_moves,3);


    //now for the special moves O-O and O-O-O (short and long castling)
    //i am going to just check if there is a rook where it is supposed to be
    //the tiles are empty
    //and the pieces have not moved.
    //after that move will occur
    // the extra checking wether the kings path is safe will come later by the checking function!

    castling(board,posx,posy,the_avail_moves); //roke

}
