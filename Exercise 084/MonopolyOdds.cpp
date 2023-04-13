/*   Monopoly odds
 
Problem 84
In the game, Monopoly, the standard board is set up in the following way:

p084_monopoly_board.png
A player starts on the GO square and adds the scores on two 6-sided dice 
to determine the number of squares they advance in a clockwise direction. 
Without any further rules we would expect to visit each square with equal 
probability: 2.5%. However, landing on G2J (Go To Jail), CC (community chest), 
and CH (chance) changes this distribution.

In addition to G2J, and one card from each of CC and CH, that orders the player 
to go directly to jail, if a player rolls three consecutive doubles, they do not 
advance the result of their 3rd roll. Instead they proceed directly to jail.

At the beginning of the game, the CC and CH cards are shuffled. When a player 
lands on CC or CH they take a card from the top of the respective pile and, 
after following the instructions, it is returned to the bottom of the pile. 
There are sixteen cards in each pile, but for the purpose of this problem we are 
only concerned with cards that order a movement; any instruction not concerned 
with movement will be ignored and the player will remain on the CC/CH square.

Community Chest (2/16 cards):
Advance to GO
Go to JAIL
Chance (10/16 cards):
Advance to GO
Go to JAIL
Go to C1
Go to E3
Go to H2
Go to R1
Go to next R (railway company)
Go to next R
Go to next U (utility company)
Go back 3 squares.
The heart of this problem concerns the likelihood of visiting a particular square. That is, the probability of finishing at that square after a roll. For this reason it should be clear that, with the exception of G2J for which the probability of finishing on it is zero, the CH squares will have the lowest probabilities, as 5/8 request a movement to another square, and it is the final square that the player finishes at on each roll that we are interested in. We shall make no distinction between "Just Visiting" and being sent to JAIL, and we shall also ignore the rule about requiring a double to "get out of jail", assuming that they pay to get out on their next turn.

By starting at GO and numbering the squares sequentially from 00 to 39 we can concatenate these two-digit numbers to produce strings that correspond with sets of squares.

Statistically it can be shown that the three most popular squares, in order, are JAIL (6.24%) = Square 10, E3 (3.18%) = Square 24, and GO (3.09%) = Square 00. So these three most popular squares can be listed with the six-digit modal string: 102400.

If, instead of using two 6-sided dice, two 4-sided dice are used, find the six-digit modal string.


Pergjigje:  101524   */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <tr1/cstdint>
#include <deque>
#include <algorithm>
#include <utility>

enum square_t
{
      GO,   A1,  CC1,   A2,   T1,   R1,   B1,  CH1,   B2,   B3,
    JAIL,   C1,   U1,   C2,   C3,   R2,   D1,  CC2,   D2,   D3,
      FP,   E1,  CH2,   E2,   E3,   R3,   F1,   F2,   U2,   F3,
     G2J,   G1,   G2,  CC3,   G3,   R4,  CH3,   H1,   T2,   H2
};

enum chance_cards_t
{
    CH_GO, CH_JAIL, CH_C1, CH_E3, CH_H2, CH_R1, CH_NEXTR1, CH_NEXTR2, CH_NEXTU,
    CH_BACK3, STAY1, STAY2, STAY3, STAY4, STAY5, STAY6
};

enum comm_chest_cards_t
{
    CC_GO, CC_JAIL, CC_1, CC_2, CC_3, CC_4, CC_5, CC_6, CC_7, CC_8, CC_9,
    CC_10, CC_11, CC_12, CC_13, CC_14
};

void get_roll (std::ifstream &urandom, int &die1, int &die2)
{
    char ch;
    urandom >> ch;
    die1 = (ch & 3) + 1;
    die2 = ((ch & 15) >> 2) + 1;
}   

struct monopoly_state_t
{
    uintmax_t ref [40];
    square_t cur_square;
    bool doubles_history [3];
    uintmax_t move_number;
    chance_cards_t chance_cards [16];
    int top_of_chance_deck;
    comm_chest_cards_t comm_chest_cards [16];
    int top_of_comm_chest_deck;
    
    monopoly_state_t (std::ifstream &urandom)
    {
	memset (ref, 0, sizeof (ref));
	cur_square = GO;
	memset (doubles_history, 0, sizeof (doubles_history));
	move_number = 0;
	const chance_cards_t chance_val [] =
	{
	    CH_GO, CH_JAIL, CH_C1, CH_E3, CH_H2, CH_R1, CH_NEXTR1, CH_NEXTR2,
	    CH_NEXTU, CH_BACK3, STAY1, STAY2, STAY3, STAY4, STAY5, STAY6
	};
	
	std::deque<chance_cards_t> unshuffled_chance_deck (chance_val,
							   chance_val + 16);
	top_of_chance_deck = 0;
	#define RANDOM_CARD(rnd,deck,idx) (deck [idx = rnd % deck.size ()])
	while (!unshuffled_chance_deck.empty ())
	{
	    char ch;
	    urandom >> ch;
	    int idx;
	    chance_cards [top_of_chance_deck ++] = RANDOM_CARD (ch, unshuffled_chance_deck, idx);
	    unshuffled_chance_deck.erase (unshuffled_chance_deck.begin () + idx);
	}
	
	const comm_chest_cards_t comm_chest_val [] =
	{
	    CC_GO, CC_JAIL, CC_1, CC_2, CC_3, CC_4, CC_5, CC_6, CC_7, CC_8,
	    CC_9, CC_10, CC_11, CC_12, CC_13, CC_14
	};
	top_of_chance_deck = 0;
	
	std::deque<comm_chest_cards_t> unshuffled_comm_chest_deck (comm_chest_val,
								   comm_chest_val + 16);
	
	top_of_comm_chest_deck = 0;
	while (!unshuffled_comm_chest_deck.empty ())
	{
	    char ch;
	    urandom >> ch;
	    int idx;
	    comm_chest_cards [top_of_comm_chest_deck ++] = RANDOM_CARD (ch, unshuffled_comm_chest_deck, idx);
	    unshuffled_comm_chest_deck.erase (unshuffled_comm_chest_deck.begin () + idx);
	}
	top_of_comm_chest_deck = 0;
    }
};

void play_monopoly (monopoly_state_t &state, std::ifstream &urandom)
{
    int die1, die2;
    get_roll (urandom, die1, die2);
    state.doubles_history [state.move_number % 3] = die1 == die2;
    ++ state.move_number;
    
    if (state.doubles_history [0] && state.doubles_history [1] &&
	state.doubles_history [2])
    {
	state.cur_square = JAIL;
	goto end;
    }
    
    state.cur_square = (square_t) ((state.cur_square + die1 + die2) % 40);
    switch (state.cur_square)
    {
	case CC1:
	case CC2:
	case CC3:
	switch (state.comm_chest_cards [state.top_of_comm_chest_deck])
	{
	    case CC_GO:
	    state.cur_square = GO;
	    break;
	    
	    case CC_JAIL:
	    state.cur_square = JAIL;
	    break;
	    
	    default:
	    break;
	}
	state.top_of_comm_chest_deck = (state.top_of_comm_chest_deck + 1) % 16;
	goto end;
	
	case CH1:
	case CH2:
	case CH3:
	switch (state.chance_cards [state.top_of_chance_deck])
	{
	    case CH_GO:
	    state.cur_square = GO;
	    break;
	   
	    case CH_JAIL:
	    state.cur_square = JAIL;
	    break;
	    
	    case CH_C1:
	    state.cur_square = C1;
	    break;
	    
	    case CH_E3:
	    state.cur_square = E3;
	    break;
	    
	    case CH_H2:
	    state.cur_square = H2;
	    break;
	    
	    case CH_R1:
	    state.cur_square = R1;
	    break;
	    
	    case CH_NEXTR1:
	    case CH_NEXTR2:
	    switch (state.cur_square)
	    {
		case CH1:
		state.cur_square = R2;
		break;
		
		case CH2:
		state.cur_square = R3;
		break;
		
		case CH3:
		state.cur_square = R1;
		break;
		
		default:
		std::cout << __FILE__ << ':' << __LINE__ <<
		    ": invalid chance square " << state.cur_square << std::endl;
		break;
	    }
	    break;
	    
	    case CH_NEXTU:
	    switch (state.cur_square)
	    {
		case CH1:
		case CH3:
		state.cur_square = U1;
		break;
		
		case CH2:
		state.cur_square = U2;
		break;
		
		default:
		std::cout << __FILE__ << ':' << __LINE__ <<
		    ": invalid chance square " << state.cur_square << std::endl;
		break;
	    }
	    break;
	    
	    case CH_BACK3:
	    state.cur_square = (square_t) ((state.cur_square + 40 - 3) % 40);
	    break;
	    
	    default:
	    break;
	}
	state.top_of_chance_deck = (state.top_of_chance_deck + 1) % 16;
	goto end;
	
	case G2J:
	state.cur_square = JAIL;
	goto end;
	
	default:
	goto end;
    }
    
    end:
    ++ state.ref [state.cur_square];
}

bool comp (const std::pair<int, uintmax_t> &a, const std::pair<int, uintmax_t> &b)
{
    return a.second >= b.second;
}

int main ()
{
    std::ifstream urandom ("/dev/urandom", std::ios::in);
    
    monopoly_state_t state (urandom);
    
    while (state.move_number < 100000)
	play_monopoly (state, urandom);
    
    urandom.close ();
    
    std::deque<std::pair<int, uintmax_t> > ranks (40);
    for (int i = 0; i < 40; ++i)
	ranks [i] = std::make_pair (i, state.ref [i]);
    
    std::partial_sort (ranks.begin (), ranks.begin () + 3, ranks.end (), &comp);
    
    std::cout << std::setw (2) << std::setfill ('0') << ranks [0].first <<
	         std::setw (2) << std::setfill ('0') << ranks [1].first <<
	         std::setw (2) << std::setfill ('0') << ranks [2].first <<
	         std::endl;

    return 0;
}