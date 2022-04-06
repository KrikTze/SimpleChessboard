#include "chessboard.h"

chessboard::chessboard()
{
    vector<Tile*> k;
    this->to_move=0;
    cout << "Hello and welcome to a new game of chess " << endl;
    for(int i=0;i<8;i++)
    {
        this->board.push_back(k);
        for(int j=0;j<8;j++)
        {
            this->board[i].push_back(new Tile(i,j));
        }
    }
    cout << "This is the board before Its population" << endl;
    this->print_chessboard_2();

    cout << "This is after its population" << endl;
    //
    //lets create sides
    create_side(0);
    create_side(1);
    this->print_chessboard_2();

    cout << "Now press play to move on to the game" << endl;

}

void chessboard::create_side(int side)
{
    char side_name;
    int piece_row;
    int pawn_row;
    char Pawn_name;
    char bishop_name;
    char knight_name;
    char rook_name;
    char queen_name;
    char king_name;

    if(side==0)
    {//white side
        side_name='W';
        piece_row=0;
        pawn_row=1;
        Pawn_name='P';
        knight_name='N';
        bishop_name='B';
        rook_name='R';
        queen_name='Q';
        king_name='K';
    }
    else
    {//black side
        side_name='B';
        piece_row=7;
        pawn_row=6;
        Pawn_name='1';
        knight_name='2';
        bishop_name='3';
        rook_name='4';
        queen_name='5';
        king_name='9';

    }
    //pawns
    Pawn *temp;
    for(int i=0;i<8;i++)
    {
        temp = new Pawn(side_name,Pawn_name);
        this->board[pawn_row][i]->set_piece(temp);
    }
    Knight *temp_knight;
    Bishop *temp_bishop;
    Rook *temp_rook;
    Queen *temp_queen;
    King *temp_king;
    for(int i=0;i<8;i++)
    {
        if(i==0 || i==0+7)
        {
            temp_rook=new Rook(side_name,rook_name);
            this->board[piece_row][i]->set_piece(temp_rook);
        }
        else if (i==1 || i==6)
        {
            temp_knight=new Knight(side_name,knight_name);
            this->board[piece_row][i]->set_piece(temp_knight);

        }
        else if (i==2 || i==5)
        {
            temp_bishop=new Bishop(side_name,bishop_name);
            this->board[piece_row][i]->set_piece(temp_bishop);

        }
        else if(i==3)
        {
            temp_queen=new Queen(side_name,queen_name);
            this->board[piece_row][i]->set_piece(temp_queen);
        }
        else
        {
            temp_king=new King(side_name,king_name);
            this->board[piece_row][i]->set_piece(temp_king);

        }
        
    }


}

/*void chessboard::print_chessboard()
{
    for(int i=63;i>=0;i--)
    {
        Piece *temp;
        if(this->board[i]->is_piece()==NULL)
        {
            cout << "*" ;
        }
        else
        {
            temp=this->board[i]->is_piece();
            cout << temp->get_name();
        }
        if((i)%8==0)
        {
            cout << endl;
        }
    }
} */

void chessboard::print_chessboard_2()
{
    Piece *temp;

    for(int i=7;i>=0;i--)
    {
        for(int j=0;j<8;j++)
        {
            if(this->board[i][j]->is_piece()==NULL)
            {
                cout << "*" ;
            }
            else
            {
                temp=this->board[i][j]->is_piece();
                cout << temp->get_name();
            }            
        }
        cout << endl;
    }
}

int chessboard::who_moves() 
{
    if(this->to_move%2==0)
    {
        cout << "White to move" << endl;
        return 0;
    }
    else
    {
        cout << "Black to move" << endl;
        return 1;
    }
}

void print_options()
{
    cout << "Press 1 to see who moves" << endl;
    cout << "Press 2 to see the available moves" << endl;
    cout << "Press 3 to play a move" << endl;
    //cout << "Press 4 to see a pieces avail moves " << endl;
    cout << "Press 0 to exit the game" << endl;

}
void chessboard::play()
{
    cout << "Welcome to a brand new game of chess" << endl;
    //while h switch case gia ta memes?
    int over=1;
    int opt=0;
    string the_move;
    while(over)
    {
        print_options();
        cin >> opt;
        switch (opt)
        {
            case 1:
                this->who_moves();
                break;
            case 2:
                avail_moves2();
                break;
            case 3:
                cout << "Type the exact move" << endl;
                cin >> the_move;
                this->play_a_move(the_move);
                this->to_move++;
                this->print_chessboard_2();
                this->who_moves();
                break;
            /*case 4:
                avail_moves_piece();
                break; */
            case 0:
                over=0;
                break;
            default:
                cout << "No valid options given" << endl;
                break;
        }

    }
        
}

//currently for debugging purposes
void chessboard::avail_moves_piece()
{
    char the_piece;
    cout << "Give me the piece name" << endl;
    cin >> the_piece;
    //for now i am going to assume that the input is correct
    //will come back to cover this later
    vector<string> the_avail_moves;
    int side=who_moves();
    char the_side;
    if(side==0)
    {
        the_side='W';
    }
    else
    {
        the_side='B';
    }
    Piece *temp_piece;
    for(int i=0; i<8 ;i++)
    {
        for(int j=0;j<8;j++)
        {
            //cout << "Tile name and pos x" << board[i][j]->get_tile_name() << " " << i << endl;
            if(board[i][j]->is_piece()!=NULL)
            {
                temp_piece=board[i][j]->is_piece();
                if(temp_piece->get_side()==the_side)
                {//check if it is the right side
                    if(temp_piece->get_name()==the_piece)
                    {
                        cout << "We are currently looking for the " << the_piece << endl;
                        if(temp_piece->get_name()=='P' || temp_piece->get_name()=='1')
                        {//check if its a pawn
                        Pawn* temp_pawn = (Pawn*)temp_piece;
                        temp_pawn->move(board,i,j,the_avail_moves);
                        }
                        //rook
                        if(temp_piece->get_name()=='R'|| temp_piece->get_name()=='4')
                        {
                            Rook* temp_rook = (Rook*)temp_piece;
                            temp_rook->move(board,i,j,the_avail_moves);
                        }
                        //bishop
                        if(temp_piece->get_name()=='B' || temp_piece->get_name()=='3')
                        {
                            Bishop* temp_bishop=(Bishop*)temp_piece;
                            temp_bishop->move(board,i,j,the_avail_moves);
                        }
                        if(temp_piece->get_name()=='Q' || temp_piece->get_name()=='5')
                        {
                            Queen* temp_queen=(Queen*)temp_piece;
                            temp_queen->move(board,i,j,the_avail_moves);
                        }
                        if(temp_piece->get_name()=='K' || temp_piece->get_name()=='9')
                        {
                            King* temp_king=(King*)temp_piece;
                            temp_king->move(board,i,j,the_avail_moves);
                        }
                        if(temp_piece->get_name()=='N' || temp_piece->get_name()=='2')
                        {
                            Knight* temp_knight=(Knight*)temp_piece;
                            temp_knight->move(board,i,j,the_avail_moves);
                        }
                    }
                }
            }
        }
    }
    cout << "the avail size " << the_avail_moves.size() <<endl;

}

void chessboard::avail_moves2()
{
    vector<string> the_avail_moves;
    the_avail_moves=avail_moves();
    en_passant_add(the_avail_moves);
    vector<string> the_moves;
    the_moves = avail_move_checker(the_avail_moves);
    for(int i=0;i<the_avail_moves.size();i++)
    {
        cout << the_avail_moves[i] << endl;
    }
}

vector<string> chessboard::avail_moves()
{
    vector<string> the_avail_moves;
    int side=who_moves();
    char the_side;
    if(side==0)
    {
        the_side='W';
    }
    else
    {
        the_side='B';
    }
    Piece *temp_piece;
    for(int i=0; i<8 ;i++)
    {
        for(int j=0;j<8;j++)
        {
            //cout << "Tile name and pos x" << board[i][j]->get_tile_name() << " " << i << endl;
            if(board[i][j]->is_piece()!=NULL)
            {
                temp_piece=board[i][j]->is_piece();
                if(temp_piece->get_side()==the_side)
                {//check if it is the right side
                    if(temp_piece->get_name()=='P' || temp_piece->get_name()=='1')
                    {//check if its a pawn
                    Pawn* temp_pawn = (Pawn*)temp_piece;
                    temp_pawn->move(board,i,j,the_avail_moves);
                    }
                    if(temp_piece->get_name()=='R'|| temp_piece->get_name()=='4')
                    {
                        Rook* temp_rook = (Rook*)temp_piece;
                        temp_rook->move(board,i,j,the_avail_moves);
                    }
                    //bishop
                    if(temp_piece->get_name()=='B' || temp_piece->get_name()=='3')
                    {
                        Bishop* temp_bishop=(Bishop*)temp_piece;
                        temp_bishop->move(board,i,j,the_avail_moves);
                    }
                    if(temp_piece->get_name()=='Q' || temp_piece->get_name()=='5')
                    {
                        Queen* temp_queen=(Queen*)temp_piece;
                        temp_queen->move(board,i,j,the_avail_moves);
                    }
                    if(temp_piece->get_name()=='K' || temp_piece->get_name()=='9')
                    {
                        King* temp_king=(King*)temp_piece;
                        temp_king->move(board,i,j,the_avail_moves);
                    }
                    if(temp_piece->get_name()=='N' || temp_piece->get_name()=='2')
                    {
                        Knight* temp_knight=(Knight*)temp_piece;
                        temp_knight->move(board,i,j,the_avail_moves);
                    }
                }
            }
        }
    }
    cout << "the avail size " << the_avail_moves.size() <<endl;
    return the_avail_moves;
}

Tile* chessboard::find_tile(string tile_name)
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

void chessboard::make_move(Tile *old_tile,Tile* new_tile)
{
    if(new_tile->is_piece()!=NULL)
    {
       new_tile->delete_piece();
    }
    new_tile->set_piece(old_tile->is_piece());
    old_tile->move_piece();
    new_tile->is_piece()->set_has_moved();
}

void chessboard::make_promotion(Tile *old_tile,Tile* new_tile,char new_piece)
{
    if(new_tile->is_piece()!=NULL)
    {
       new_tile->delete_piece();
    }
    //
    if(old_tile->is_piece()!=NULL)// this should always be the case
    {
        old_tile->delete_piece(); // we do not need the pawn anymore, we should create the new type of piece
        old_tile->move_piece();
    }
    char side;
    if(who_moves()==0)
    {
        side = 'W';
    }
    else
    {
        side='B';
    }
    Knight *new_knight;
    Rook* new_rook;
    Bishop* new_bishop;
    Queen * new_queen;

    if(new_piece=='N' || new_piece =='2')
    {
        new_knight=new Knight(side,new_piece);
        new_tile->set_piece(new_knight);
    }
    else if(new_piece=='B' || new_piece =='3')
    {
        new_bishop=new Bishop(side,new_piece);
        new_tile->set_piece(new_bishop);
    }
    else if(new_piece=='R' || new_piece =='4')
    {
        new_rook=new Rook(side,new_piece);
        new_tile->set_piece(new_rook);
    }
    else if(new_piece=='Q' || new_piece =='5')
    {
        new_queen=new Queen(side,new_piece);
        new_tile->set_piece(new_queen);
    }


    new_tile->is_piece()->set_has_moved();

}
///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

//CREATE MORE CASES
//AND DO SEPERATE REVERTS
// THIS CAN WORK
///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

void chessboard::move_revert_short_castle()
{
    //old tile where it currently is
    //new tile where it should be
    //use the who_moves but backwards
    Tile *old_tile_king;
    Tile *old_tile_rook;
    Tile *new_tile_king;
    Tile *new_tile_rook;
    string old_tile_name_king;
    string old_tile_name_rook;
    string new_tile_name_king;
    string new_tile_name_rook;
    Tile *old_tile;
    Tile *new_tile;
    if(who_moves()==0)
    {//actually black to restore
        
        old_tile_name_rook="f8";
        new_tile_name_rook="h8";
        old_tile_name_king="g8";
        new_tile_name_king="e8";
        
    }
    else
    {//actually white to restore
    
        old_tile_name_rook="f1";
        new_tile_name_rook="h1";
        old_tile_name_king="g1";
        new_tile_name_king="e1";
    
        
    }

    //short castling
    old_tile_king=find_tile(old_tile_name_king);
    old_tile_rook=find_tile(old_tile_name_rook);
    new_tile_king=find_tile(new_tile_name_king);
    new_tile_rook=find_tile(new_tile_name_rook);
    make_move(old_tile_king,new_tile_king);
    make_move(old_tile_rook,new_tile_rook);
    new_tile_king->is_piece()->reset_has_moved();
    new_tile_rook->is_piece()->reset_has_moved();
    
}

void chessboard::move_revert_long_castle()
{
    Tile *old_tile_king;
    Tile *old_tile_rook;
    Tile *new_tile_king;
    Tile *new_tile_rook;
    string old_tile_name_king;
    string old_tile_name_rook;
    string new_tile_name_king;
    string new_tile_name_rook;
    Tile *old_tile;
    Tile *new_tile;
    if(who_moves()==0)
    {//actually black to restore
        old_tile_name_rook="d8";
        new_tile_name_rook="a8";
        old_tile_name_king="c8";
        new_tile_name_king="e8";
        
    }
    else
    {//actually white to restore

        old_tile_name_rook="d1";
        new_tile_name_rook="a1";
        old_tile_name_king="c1";
        new_tile_name_king="e1";
        
        
    }

    //short castling
    old_tile_king=find_tile(old_tile_name_king);
    old_tile_rook=find_tile(old_tile_name_rook);
    new_tile_king=find_tile(new_tile_name_king);
    new_tile_rook=find_tile(new_tile_name_rook);
    make_move(old_tile_king,new_tile_king);
    make_move(old_tile_rook,new_tile_rook);
    new_tile_king->is_piece()->reset_has_moved();
    new_tile_rook->is_piece()->reset_has_moved();


}

void chessboard::move_revert_simple_move(string the_move,int mine_had_moved)
{
    //old tile where it should go back too
    Tile* old_tile;
    Tile* new_tile;
    old_tile = find_tile(the_move.substr(0,2));
    new_tile = find_tile(the_move.substr(the_move.length()-2));
    make_move(new_tile,old_tile);
    if(mine_had_moved==0)
    {
        old_tile->is_piece()->reset_has_moved();
    }
    
}

void chessboard::move_revert_simple_captures(string the_move,char piece_name,int other_had_moved,int mine_had_moved)
{
    Tile* old_tile;
    Tile* new_tile;
    Piece *the_captured_piece;
    old_tile = find_tile(the_move.substr(0,2));
    new_tile = find_tile(the_move.substr(the_move.length()-2));
    make_move(new_tile,old_tile);
    if(mine_had_moved==0)
    {
        old_tile->is_piece()->reset_has_moved();
    }
    //
    char side;
    if(who_moves()==0)
    {
        side='W';
    }    
    else
    {
        side='B';
    }
    Knight *new_knight;
    Rook * new_rook;
    Bishop *new_bishop;
    Queen *new_queen;
    Pawn * new_pawn;
    if(piece_name=='N' || piece_name =='2')
    {
        new_knight=new Knight(side,piece_name);
        new_tile->set_piece(new_knight);
    }
    else if(piece_name=='B' || piece_name =='3')
    {
        new_bishop=new Bishop(side,piece_name);
        new_tile->set_piece(new_bishop);
    }
    else if(piece_name=='R' || piece_name =='4')
    {
        new_rook=new Rook(side,piece_name);
        new_tile->set_piece(new_rook);
    }
    else if(piece_name=='Q' || piece_name =='5')
    {
        new_queen=new Queen(side,piece_name);
        new_tile->set_piece(new_queen);
    }
    else if(piece_name=='P' || piece_name =='1')
    {
        new_pawn = new Pawn(side,piece_name);
        new_tile->set_piece(new_pawn);
    }

    if(other_had_moved==1)
    {
        new_tile->is_piece()->set_has_moved();
    }
}

void chessboard::move_revert_promo(string the_move)
{
    Tile* old_tile;
    Tile* new_tile;

    old_tile = find_tile(the_move.substr(0,2)); //the tile of the pawn

    new_tile = find_tile(the_move.substr(the_move.length()-4,2)); // the new tile


    Pawn *new_pawn;
    char side;
    char piece_name;
    if(who_moves()==0)
    {
        side='W';
        piece_name='P';

    }    
    else
    {
        side='B';
        piece_name='1';
    }
    //the pawn is coming back!
    new_pawn = new Pawn(side,piece_name);
    old_tile->set_piece(new_pawn);
    old_tile->is_piece()->set_has_moved();
    new_tile->delete_piece();

}

void chessboard::move_revert_promo_captures(string the_move,char piece_name,int other_had_moved)
{
    Tile* old_tile;
    Tile* new_tile;

    old_tile = find_tile(the_move.substr(0,2)); //the tile of the pawn

    new_tile = find_tile(the_move.substr(the_move.length()-4,2)); // the new tile


    Pawn *new_pawn;
    char side;
    char pawn_name;
    if(who_moves()==0)
    {
        side='W';
        pawn_name='P';

    }    
    else
    {
        side='B';
        pawn_name='1';
    }
    //the pawn is coming back!
    new_pawn = new Pawn(side,pawn_name);
    old_tile->set_piece(new_pawn);
    old_tile->is_piece()->set_has_moved();
    new_tile->delete_piece();

    // now recreate the old piece
    Knight *new_knight;
    Rook * new_rook;
    Bishop *new_bishop;
    Queen *new_queen;
    if(piece_name=='N' || piece_name =='2')
    {
        new_knight=new Knight(side,piece_name);
        new_tile->set_piece(new_knight);
    }
    else if(piece_name=='B' || piece_name =='3')
    {
        new_bishop=new Bishop(side,piece_name);
        new_tile->set_piece(new_bishop);
    }
    else if(piece_name=='R' || piece_name =='4')
    {
        new_rook=new Rook(side,piece_name);
        new_tile->set_piece(new_rook);
    }
    else if(piece_name=='Q' || piece_name =='5')
    {
        new_queen=new Queen(side,piece_name);
        new_tile->set_piece(new_queen);
    }


    if(other_had_moved==1)
    {
        new_tile->is_piece()->set_has_moved();
    }

}

void chessboard::move_revert_en_passant(string the_move)
{
    int difference;
    Tile* old_tile;
    Tile* new_tile;
    char side;
    char pawn_name;
    Pawn *new_pawn;
    string en_passant_pawn_tile;
    Tile * en_passant_tile;
    if(who_moves()==0) // opposite because the other one is supposed to be playing
    {
        difference=1;
        pawn_name='P';
        side = 'W';
    }
    else
    {
        difference=-1;
        pawn_name='1';
        side = 'B';
    }
    old_tile = find_tile(the_move.substr(0,2));
    new_tile = find_tile(the_move.substr(4,2));
    make_move(new_tile,old_tile);

    en_passant_pawn_tile = new_tile->get_tile_name();
    en_passant_pawn_tile[1] = en_passant_pawn_tile[1] + difference;
    cout << en_passant_pawn_tile << "she shallow" << endl;
    en_passant_tile=find_tile(en_passant_pawn_tile);
    new_pawn = new Pawn(side,pawn_name);
    en_passant_tile->set_piece(new_pawn);
    en_passant_tile->is_piece()->set_has_moved();

}

vector<string> chessboard::avail_move_checker(vector<string> &the_avail_moves)
{
    string the_move;
    Tile* old_tile;
    Tile* new_tile;
    Tile* king_pos; //this should even maybe be statically part of the chessboard instead of dynamically finding it each time
    string king_pos_tile_name;
    char king_name;
    int flag=0;
    int flag2=0;
    vector<string> the_valid_moves; // to be returned

    vector<string> the_new_moves; // the ones we will use for checking

    char piece_name;
    int other_had_moved;
    int mine_had_moved;

    //we will need to create the next state to decide
    //wether it will be dangerous for our king.
    //so we will have to play check and undo the move.
    Piece *prev_piece_on_tile;
    int piece1_has_moved;
    int piece2_has_moved;
    string original_pos;
    string new_pos;
    string captures_pos;
    //
    string dangerous_tile1;
    string dangerous_tile2_name;
    string dangerous_tile3_name;
    Tile* dangerous_tile2;
    Tile* dangerous_tile3;
    //
    string en_passant_pawn_tile;
    Tile * en_passant_tile;
    int difference;
    int was_special; //0 no 1 short castle 2 long castle 3 promo 4 enpassant
    if(who_moves()==0)
    {
        difference=-1;
    }
    else
    {
        difference=1;
    }

    for(int i=0;i<the_avail_moves.size();i++)
    {
        the_move=the_avail_moves[i];
        if(the_move=="O-O") // small castle
        {
            if(who_moves()==0) //white to move
            {
                old_tile=find_tile("e1");
                new_tile=find_tile("g1");
                dangerous_tile1="f1";
                dangerous_tile2_name="g2";
                dangerous_tile2=this->find_tile(dangerous_tile2_name);
                dangerous_tile3_name="e2";
                dangerous_tile3=this->find_tile(dangerous_tile3_name);
                make_move(old_tile,new_tile);
                old_tile=find_tile("h1");
                new_tile=find_tile("f1");
                make_move(old_tile,new_tile);
            }
            else
            {
                old_tile=find_tile("e8");
                new_tile=find_tile("g8");
                dangerous_tile1="f8";
                dangerous_tile2_name="g7";
                dangerous_tile2=this->find_tile(dangerous_tile2_name);
                dangerous_tile3_name="e7";
                dangerous_tile3=this->find_tile(dangerous_tile3_name);
                make_move(old_tile,new_tile);
                old_tile=find_tile("h8");
                new_tile=find_tile("f8");
                make_move(old_tile,new_tile);

            }
            was_special=1;
        }
        else if(the_move=="O-O-O") //big castle
        {
            if(who_moves()==0) //white to move
            {
                old_tile=find_tile("e1");
                new_tile=find_tile("c1");
                dangerous_tile1="d1";
                dangerous_tile2_name="e2";
                dangerous_tile2=this->find_tile(dangerous_tile2_name);
                dangerous_tile3_name="c2";
                dangerous_tile3=this->find_tile(dangerous_tile3_name);

                make_move(old_tile,new_tile);
                old_tile=find_tile("a1");
                new_tile=find_tile("d1");
                make_move(old_tile,new_tile);
            }
            else
            {
                old_tile=find_tile("e8");
                new_tile=find_tile("c8");
                dangerous_tile1="d8";
                dangerous_tile2_name="e7";
                dangerous_tile2=this->find_tile(dangerous_tile2_name);
                dangerous_tile3_name="c7";
                dangerous_tile3=this->find_tile(dangerous_tile3_name);
                make_move(old_tile,new_tile);
                old_tile=find_tile("a8");
                new_tile=find_tile("d8");
                make_move(old_tile,new_tile);
            }
            was_special=2;

        }
        else if(the_move[the_move.length()-1]=='L')
        {
            old_tile = find_tile(the_move.substr(0,2));
            new_tile = find_tile(the_move.substr(4,2));
            cout << "Yoooooo " << the_move.substr(4,2) << endl;
            en_passant_pawn_tile = new_tile->get_tile_name();
            en_passant_pawn_tile[1]= en_passant_pawn_tile[1] + difference;
            cout << "Yoooooo " << en_passant_pawn_tile << endl;

            en_passant_tile=find_tile(en_passant_pawn_tile);
            make_move(old_tile,new_tile);
            if(en_passant_tile->is_piece()!=NULL)
            {
                en_passant_tile->delete_piece();
            }
            was_special=6;
            
        }
        else if(the_move.length()>=7) //promotion hopefully
        {
            old_tile = find_tile(the_move.substr(0,2));
            new_tile = find_tile(the_move.substr(the_move.length()-4,2));

            //cout << "This is the tileee " << new_tile->get_tile_name() << endl << endl;
            char new_piece = the_move[the_move.length()-1]; //the new piece
            if(new_tile->is_piece()!=NULL)  
            {
                piece_name=new_tile->is_piece()->get_name();
                other_had_moved=new_tile->is_piece()->get_has_moved();
            }
            make_promotion(old_tile,new_tile,new_piece);
            was_special=3;

            //check if it's captures
            if(the_move[3]=='x')
            {//its a capture
                was_special=4;
                //prev_piece_on_tile = 
            }
        }
        else
        {
            old_tile = find_tile(the_move.substr(0,2));
            new_tile = find_tile(the_move.substr(the_move.length()-2));
            if(new_tile->is_piece()!=NULL)  
            {
                piece_name=new_tile->is_piece()->get_name();
                other_had_moved=new_tile->is_piece()->get_has_moved();
            }
            mine_had_moved=old_tile->is_piece()->get_has_moved();
            make_move(old_tile,new_tile);
            was_special=0;
            //check if it's captures
            if(the_move[3]=='x')
            {//its a capture
                was_special=5;
                //prev_piece_on_tile = 
            }

        }

        if(who_moves()==0) //constantly finding the king
        {
            king_name='K';
        }
        else
        {
            king_name='9';
        }
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(board[i][j]->is_piece()!=NULL)
                {
                    if (board[i][j]->is_piece()->get_name()==king_name)
                    {
                        king_pos=board[i][j];
                        flag=1;
                    }
                    
                }
                if(flag)
                {
                    break;
                }
            }
            if(flag)
            {
                break;
            }
        }
        if(flag!=1)
        {
            cout << "Something horrible has happened" << endl;
            return the_valid_moves;
        }

        this->to_move++;
        the_new_moves=avail_moves();
        string to_the_path;
        char dangerous_pawns;
        //check for the king getting captured
        for(int j=0;j<the_new_moves.size();j++)
        {
            if(the_new_moves[j].length()>4)
            {//every capture is at least 5 char. a2Pxa3
                if(the_new_moves[j][3]=='x')
                {
                    captures_pos=the_new_moves[j].substr(4,2);
                    if(captures_pos==king_pos->get_tile_name())
                    {
                        flag2=1;
                        break;
                    }
                }

            }
            //then the castling blocker
            //this works fine :3
            if(the_move=="O-O") // just some checking for the king trying to cross the roads...
            {
                to_the_path=the_new_moves[j].substr(the_new_moves[j].length()-2);
                if(to_the_path==dangerous_tile1)
                {
                    flag2=1;
                    break;
                }
                if(who_moves()==0) // black castled
                {
                    dangerous_pawns='P';
                }
                else
                {
                    dangerous_pawns='1';
                }
                if(dangerous_tile2->is_piece()!=NULL)
                {
                    if(dangerous_tile2->is_piece()->get_name()==dangerous_pawns)
                    {
                        flag2=1;
                        break;
                    }
                }
                if(dangerous_tile3->is_piece()!=NULL)
                {
                    if(dangerous_tile3->is_piece()->get_name()==dangerous_pawns)
                    {
                        flag2=1;
                        break;
                    }
                }
            }
            else if(the_move=="O-O-O")
            {
                to_the_path=the_new_moves[j].substr(the_new_moves[j].length()-2);
                if(to_the_path==dangerous_tile1)
                {

                    flag2=1;
                    break;
                }
                if(who_moves()==0) // black castled
                {
                    dangerous_pawns='P';
                }
                else
                {
                    dangerous_pawns='1';
                }
                if(dangerous_tile2->is_piece()!=NULL)
                {
                    if(dangerous_tile2->is_piece()->get_name()==dangerous_pawns)
                    {
                        flag2=1;
                        break;
                    }
                }
                if(dangerous_tile3->is_piece()!=NULL)
                {
                    if(dangerous_tile3->is_piece()->get_name()==dangerous_pawns)
                    {
                        flag2=1;
                        break;
                    }
                }

            }
            to_the_path.clear();
            
        }
        if(!flag2)
        {
            the_valid_moves.push_back(the_move);
        }
        if(was_special==0)  //simple move
        {
            move_revert_simple_move(the_move,mine_had_moved);
        }
        else if(was_special==5) //simple captures
        {
            move_revert_simple_captures(the_move,piece_name,other_had_moved,mine_had_moved);
        }
        else if(was_special==1) //small castling
        {
            move_revert_short_castle();
        }
        else if( was_special==2) //long castling
        {
            move_revert_long_castle();
        }
        else if(was_special==3) //simple promo
        {
            move_revert_promo(the_move);
        }
        else if (was_special==4) //capture promo
        {
            move_revert_promo_captures(the_move,piece_name,other_had_moved);
        }
        else if (was_special==6)
        {
            move_revert_en_passant(the_move);
        }
        //^^ this works really really well :)
        //^^ time to add the crossing of the dangerous tiles for the king
        //^^ and en passant and its reverse and we are good to go!
        the_new_moves.clear();
        this->to_move--;
        flag=0;
        flag2=0;
        prev_piece_on_tile=NULL;
    

    }
    return the_valid_moves;
}

string en_passant_name_creator()
{

}

void chessboard::en_passant_add(vector<string> &the_avail_moves)
{
    string prev_move;
    int flag=0;
    char start_tile;
    int start_tile_int;
    char end_tile;
    int end_tile_int;
    char pawn_name_to_do;
    char pawn_name_to_be_done;
    int column;
    int difference;
    string en_passant_move1;
    string en_passant_move2;
    if(who_moves()==0)
    {
        start_tile = '7';
        start_tile_int=7;
        end_tile = '5';
        end_tile_int=4;
        pawn_name_to_do = 'P';
        pawn_name_to_be_done = '1';
        difference=1;
    }
    else
    {
        start_tile = '2';
        start_tile_int=2;
        end_tile = '4';
        end_tile_int=3;
        pawn_name_to_do='1';
        pawn_name_to_be_done='P';
        difference=-1;
    }
    if(all_the_moves.size()>0) // if it is not the first move
    {
        prev_move = all_the_moves[all_the_moves.size()-1];
        cout << "SO FAR WE COOL prequel "<< prev_move << endl;

        column=prev_move[0]-97;
        if(prev_move!="O-O")
        {
            if(prev_move[1]==start_tile && prev_move[4]==end_tile)
            {
                cout << "SO FAR WE COOL prequel" << endl;
                if(prev_move[2]==pawn_name_to_be_done)
                { // checking if it is actually a double pawn move!
                    if(column-1>=0)
                    { // checking if you have anything to the left or to ther right

                        if(board[end_tile_int][column-1]->is_piece()!=NULL)
                        {
                            cout << "SO FAR WE COOL TWICE" << endl;
                            cout << end_tile_int << endl;
                            cout << board[end_tile_int][column-1]->is_piece()->get_name() << endl;

                            if(board[end_tile_int][column-1]->is_piece()->get_name()==pawn_name_to_do)
                            {
                                en_passant_move1=board[end_tile_int][column-1]->get_tile_name()+pawn_name_to_do+"x"+board[end_tile_int+difference][column]->get_tile_name()+"L";
                                cout << en_passant_move1 << endl;
                                the_avail_moves.push_back(en_passant_move1);

                            }
                        }
                        
                    }
                    if(column+1<8)
                    { // checking if you have anything to the left or to ther right

                        if(board[end_tile_int][column+1]->is_piece()!=NULL)
                        {
                            cout << "SO FAR WE COOL TWICE" << endl;
                            cout << end_tile_int << endl;
                            cout << board[end_tile_int][column+1]->is_piece()->get_name() << endl;

                            if(board[end_tile_int][column+1]->is_piece()->get_name()==pawn_name_to_do)
                            {
                                en_passant_move1=board[end_tile_int][column+1]->get_tile_name()+pawn_name_to_do+"x"+board[end_tile_int+difference][column]->get_tile_name()+"L";
                                cout << en_passant_move1 << endl;
                                the_avail_moves.push_back(en_passant_move1);

                            }
                        }
                        
                    }
                }
            }
        }
    }

}

void chessboard::play_a_move(string the_move)
{ // here i am going to have many csp style restrictions
//+ special rules for moves like 0-0 0-0-0 promotion an passant
//it is probably going to be a little slow , but i could try to make some optimazations afterwards ?
    vector<string> the_avail_moves;
    the_avail_moves=avail_moves();
    en_passant_add(the_avail_moves);
    vector<string> the_moves;
    the_moves = avail_move_checker(the_avail_moves);
    int i=0;
    int flag=1;
    int difference;
    if(who_moves()==0)
    {
        difference=-1;
    }
    else
    {
        difference=1;
    }
    cout << "Avail moves " << the_moves.size() <<endl;
    if(the_moves.size()==0)
    {
        cout << "You got checkmated" << endl;
        exit(0);
    }
    while(flag)
    {
        for(i=0;i<the_moves.size();i++)
        {
            if(the_moves[i]==the_move)
            {
                cout << "This is a legal move and we proceed" << endl;
                flag=0;
                break;
            }
        }
        if(i==the_moves.size())
        {
            cout <<"This was not a legal move pls try again" << endl;
            cin >> the_move;
        }
    }
    
    //find the old tile?
    //find the new tile?
    //get the piece to the new tile
    //delete the piece from the old tile(dont show to it anymore)
    Tile *old_tile;
    Tile *new_tile;
    string en_passant_pawn_tile;
    Tile *en_passant_tile;
    if(the_move=="O-O") // small castle
    { 
        if(who_moves()==0) //white to move
        {
            old_tile=find_tile("e1");
            new_tile=find_tile("g1");
            make_move(old_tile,new_tile);
            old_tile=find_tile("h1");
            new_tile=find_tile("f1");
            make_move(old_tile,new_tile);
        }
        else
        {
            old_tile=find_tile("e8");
            new_tile=find_tile("g8");
            make_move(old_tile,new_tile);
            old_tile=find_tile("h8");
            new_tile=find_tile("f8");
            make_move(old_tile,new_tile);

        }
    }
    else if(the_move=="O-O-O") //big castle
    {
        if(who_moves()==0) //white to move
        {
            old_tile=find_tile("e1");
            new_tile=find_tile("c1");
            make_move(old_tile,new_tile);
            old_tile=find_tile("a1");
            new_tile=find_tile("d1");
            make_move(old_tile,new_tile);
        }
        else
        {
            old_tile=find_tile("e8");
            new_tile=find_tile("c8");
            make_move(old_tile,new_tile);
            old_tile=find_tile("a8");
            new_tile=find_tile("d8");
            make_move(old_tile,new_tile);
        }

    }
    else if(the_move[the_move.length()-1]=='L')
    {
        old_tile = find_tile(the_move.substr(0,2));
        new_tile = find_tile(the_move.substr(4,2));
        en_passant_pawn_tile = new_tile->get_tile_name();
        en_passant_pawn_tile[1] = en_passant_pawn_tile[1] + difference;
        en_passant_tile=find_tile(en_passant_pawn_tile);
        make_move(old_tile,new_tile);
        en_passant_tile->delete_piece();
        
    }
    else if(the_move.length()>=7) //promotion hopefully
    {
        old_tile = find_tile(the_move.substr(0,2));
        new_tile = find_tile(the_move.substr(the_move.length()-4,2));

        //cout << "This is the tileee " << new_tile->get_tile_name() << endl << endl;
        char new_piece = the_move[the_move.length()-1]; //the new piece
        make_promotion(old_tile,new_tile,new_piece);

    }
    else
    {
        old_tile = find_tile(the_move.substr(0,2));
        new_tile = find_tile(the_move.substr(the_move.length()-2));
        make_move(old_tile,new_tile);
    }
    all_the_moves.push_back(the_move);
    //down the line i am going to make many more changes here ^^ to account for all the different types of moves
}

chessboard::~chessboard()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            delete this->board[i][j];
        }
    }
}