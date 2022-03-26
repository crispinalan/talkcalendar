/***************************************************************************
 * GPL v3.0 license (see license document distributed with this software)
 * Dictionary to convert a word to a diphone sequence
 * Author: crispinalan@gmail.com
 ***************************************************************************/

#include <gtk/gtk.h> 
#include "dictionary.h"


GList* word_to_diphones(const char* word_str) {
	
	GList *diphone_list=NULL;
	
	char* word = g_ascii_strdown(word_str, -1); //covert to lower case
	
	//template
	//if (g_strcmp0(word,"")==0) {	
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	    
    //}	
	
	//------------------------------------------------------------------
    // Weekdays
    //------------------------------------------------------------------	
	//monday M_AH AH_N N_D D_IY 	
	if (g_strcmp0(word,"monday")==0) {	
	diphone_list = g_list_append(diphone_list, "m-ah");
	diphone_list = g_list_append(diphone_list, "ah-n");
	diphone_list = g_list_append(diphone_list, "n-d");		
	diphone_list = g_list_append(diphone_list, "d-iy");	  
    }	
	//tuesday T_UW UW_Z Z_D D_IY
	if (g_strcmp0(word,"tuesday")==0) {	
	diphone_list = g_list_append(diphone_list, "t-uw");
	diphone_list = g_list_append(diphone_list, "uw-z");
	diphone_list = g_list_append(diphone_list, "z-d");		
	diphone_list = g_list_append(diphone_list, "d-iy");	  
    }	
	//wednesday W_EH EH_N N_Z Z_D D_IY
	if (g_strcmp0(word,"wednesday")==0) {	
	diphone_list = g_list_append(diphone_list, "w-eh");
	diphone_list = g_list_append(diphone_list, "eh-n");
	diphone_list = g_list_append(diphone_list, "n-z");
	diphone_list = g_list_append(diphone_list, "z-d");			
	diphone_list = g_list_append(diphone_list, "d-iy");	  
    }	
	//thursday TH_UH UH_R R_Z Z_D D_EH EH_IY
	if (g_strcmp0(word,"thursday")==0) {	
	diphone_list = g_list_append(diphone_list, "th-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");
	diphone_list = g_list_append(diphone_list, "r-z");
	diphone_list = g_list_append(diphone_list, "z-d");			
	diphone_list = g_list_append(diphone_list, "d-eh");
	diphone_list = g_list_append(diphone_list, "eh-iy");	  
    }	
	//friday F_R R_AA AA_IY IY_D D_IY
	if (g_strcmp0(word,"friday")==0) {	
	diphone_list = g_list_append(diphone_list, "f-r");
	diphone_list = g_list_append(diphone_list, "r-aa");
	diphone_list = g_list_append(diphone_list, "aa-iy");
	diphone_list = g_list_append(diphone_list, "iy-d");			
	diphone_list = g_list_append(diphone_list, "d-iy");	  
    }	
	//saturday S_AE AE_T T_UH UH_R R_D D_IY
	if (g_strcmp0(word,"saturday")==0) {	
	diphone_list = g_list_append(diphone_list, "s-ae");
	diphone_list = g_list_append(diphone_list, "ae-t");
	diphone_list = g_list_append(diphone_list, "t-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");			
	diphone_list = g_list_append(diphone_list, "r-d");
	diphone_list = g_list_append(diphone_list, "d-iy");	  
    }	
	//sunday S_AH AH_N N_D D_EH EH_IY
	if (g_strcmp0(word,"sunday")==0) {	
	diphone_list = g_list_append(diphone_list, "s-ah");
	diphone_list = g_list_append(diphone_list, "ah-n");
	diphone_list = g_list_append(diphone_list, "n-d");
	diphone_list = g_list_append(diphone_list, "d-eh");			
	diphone_list = g_list_append(diphone_list, "eh-iy");	  
    }	
	
	
	
	//------------------------------------------------------------------
    // Ordinals (Day numbers)
    //------------------------------------------------------------------
	
	//first F_UH UH_R R_S S_T
	if (g_strcmp0(word,"first")==0) {	
	diphone_list = g_list_append(diphone_list, "f-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");
	diphone_list = g_list_append(diphone_list, "r-s");
	diphone_list = g_list_append(diphone_list, "s-t");
    }	
		
	//second S_EH EH_K K_AH AH_N N_D
	if (g_strcmp0(word,"second")==0) {	
	diphone_list = g_list_append(diphone_list, "s-eh");
	diphone_list = g_list_append(diphone_list, "eh-k");
	diphone_list = g_list_append(diphone_list, "k-ah");
	diphone_list = g_list_append(diphone_list, "an-n");			
	diphone_list = g_list_append(diphone_list, "n-d");	  
    }	
		
	//third TH_UH UH_R R_D
	if (g_strcmp0(word,"third")==0) {	
	diphone_list = g_list_append(diphone_list, "th-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");
	diphone_list = g_list_append(diphone_list, "r-d");		  
    }	
	
	//fourth F_AO AO_R R_TH
	if (g_strcmp0(word,"fourth")==0) {	
	diphone_list = g_list_append(diphone_list, "f-ao");
	diphone_list = g_list_append(diphone_list, "ao-r");
	diphone_list = g_list_append(diphone_list, "r-th");	  
    }	
		
	//fifth F_IH IH_F F_TH
	if (g_strcmp0(word,"fifth")==0) {	
	diphone_list = g_list_append(diphone_list, "f-ih");
	diphone_list = g_list_append(diphone_list, "ih-f");
	diphone_list = g_list_append(diphone_list, "f-th");	 
    }	
	//sixth S_IH IH_K K_S S_TH
	if (g_strcmp0(word,"sixth")==0) {	
	diphone_list = g_list_append(diphone_list, "s-ih");
	diphone_list = g_list_append(diphone_list, "ih-k");
	diphone_list = g_list_append(diphone_list, "k-s");
	diphone_list = g_list_append(diphone_list, "s-th");
    }	
	
    //seventh S_EH EH_V V_AH AH_N N_TH
    if (g_strcmp0(word,"seventh")==0) {	
	diphone_list = g_list_append(diphone_list, "s-eh");
	diphone_list = g_list_append(diphone_list, "eh-v");
	diphone_list = g_list_append(diphone_list, "v-ah");
	diphone_list = g_list_append(diphone_list, "ah-n");			
	diphone_list = g_list_append(diphone_list, "n-th");	  
    }	
            
	//eighth EH_IY IY_T T_TH
	if (g_strcmp0(word,"eighth")==0) {	
	diphone_list = g_list_append(diphone_list, "eh-iy");
	diphone_list = g_list_append(diphone_list, "iy-t");
	diphone_list = g_list_append(diphone_list, "t-th");	  
    }	
		
	//ninth N_AA AA_IY IY_N N_TH
	if (g_strcmp0(word,"ninth")==0) {	
	diphone_list = g_list_append(diphone_list, "n-aa");
	diphone_list = g_list_append(diphone_list, "aa-iy");
	diphone_list = g_list_append(diphone_list, "iy-n");
	diphone_list = g_list_append(diphone_list, "n-th");	
    }	
		
	//tenth T_EH EH_N N_TH
	if (g_strcmp0(word,"tenth")==0) {	
	diphone_list = g_list_append(diphone_list, "t-eh");
	diphone_list = g_list_append(diphone_list, "eh-n");
	diphone_list = g_list_append(diphone_list, "n-th");		  
    }	
	//eleventh IH_L L_EH EH_V V_AH AH_N N_TH
	if (g_strcmp0(word,"eleventh")==0) {	
	diphone_list = g_list_append(diphone_list, "ih-l");
	diphone_list = g_list_append(diphone_list, "l-eh");
	diphone_list = g_list_append(diphone_list, "eh-v");
	diphone_list = g_list_append(diphone_list, "v-ah");			
	diphone_list = g_list_append(diphone_list, "ah-n");	
	diphone_list = g_list_append(diphone_list, "n-th");  
    }	
	//twelfth T_W W_EH EH_L L_F F_TH	
	if (g_strcmp0(word,"twelfth")==0) {	
	diphone_list = g_list_append(diphone_list, "t-w");
	diphone_list = g_list_append(diphone_list, "w-eh");
	diphone_list = g_list_append(diphone_list, "eh-l");
	diphone_list = g_list_append(diphone_list, "l-f");			
	diphone_list = g_list_append(diphone_list, "f-th");	  
    }	
	//thirteenth TH_UH UH_R R_T T_IY IY_N N_TH
	if (g_strcmp0(word,"thirteenth")==0) {	
	diphone_list = g_list_append(diphone_list, "th-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");
	diphone_list = g_list_append(diphone_list, "r-t");
	diphone_list = g_list_append(diphone_list, "t-iy");			
	diphone_list = g_list_append(diphone_list, "iy-n");
	diphone_list = g_list_append(diphone_list, "n-th");		  
    }	
			 
	//fourteenth F_AO AO_R R_T T_IY IY_N N_TH 
	if (g_strcmp0(word,"fourteenth")==0) {
	
	diphone_list = g_list_append(diphone_list, "f-ao");
	diphone_list = g_list_append(diphone_list, "ao-r");
	diphone_list = g_list_append(diphone_list, "r-t");		
	diphone_list = g_list_append(diphone_list, "t-iy");
	diphone_list = g_list_append(diphone_list, "iy-n");
	diphone_list = g_list_append(diphone_list, "n-th");
	diphone_list = g_list_append(diphone_list, "th-pau");	  
    }
    
    //fifteenth F_IH IH_F F_T T_IY IY_N N_TH
    if (g_strcmp0(word,"fifteenth")==0) {	
	diphone_list = g_list_append(diphone_list, "f-ih");
	diphone_list = g_list_append(diphone_list, "ih-f");
	diphone_list = g_list_append(diphone_list, "f-t");
	diphone_list = g_list_append(diphone_list, "t-iy");			
	diphone_list = g_list_append(diphone_list, "iy-n");	
	diphone_list = g_list_append(diphone_list, "n-th");	  
    }	
    //sixteenth S_IH IH_K K_S S_T T_IY IY_N N_TH
    if (g_strcmp0(word,"sixteenth")==0) {	
	diphone_list = g_list_append(diphone_list, "s-ih");
	diphone_list = g_list_append(diphone_list, "ih-k");
	diphone_list = g_list_append(diphone_list, "k-s");
	diphone_list = g_list_append(diphone_list, "s-t");			
	diphone_list = g_list_append(diphone_list, "t-iy");
	diphone_list = g_list_append(diphone_list, "iy-n");
	diphone_list = g_list_append(diphone_list, "n-th");	  
    }	
    //seventieth S_EH EH_V V_AH AH_N N_T T_IY IY_IH IH_TH
    if (g_strcmp0(word,"seventieth")==0) {	
	diphone_list = g_list_append(diphone_list, "s-eh");
	diphone_list = g_list_append(diphone_list, "eh-v");
	diphone_list = g_list_append(diphone_list, "v-ah");
	diphone_list = g_list_append(diphone_list, "ah-n");			
	diphone_list = g_list_append(diphone_list, "n-t");
	diphone_list = g_list_append(diphone_list, "t-iy");
	diphone_list = g_list_append(diphone_list, "iy-ih");
	diphone_list = g_list_append(diphone_list, "ih-th");	  
    }	
    //eighteenth EH_IY IY_T T_IY IY_N N_TH
    if (g_strcmp0(word,"eighteenth")==0) {	
	diphone_list = g_list_append(diphone_list, "eh-iy");
	diphone_list = g_list_append(diphone_list, "iy-t");
	diphone_list = g_list_append(diphone_list, "t-iy");
	diphone_list = g_list_append(diphone_list, "iy-n");			
	diphone_list = g_list_append(diphone_list, "n-th");	  
    }	
    //nineteenth N_AA AA_IY IY_N N_T T_IY IY_N N_TH
    if (g_strcmp0(word,"nineteenth")==0) {	
	diphone_list = g_list_append(diphone_list, "n-aa");
	diphone_list = g_list_append(diphone_list, "aa-iy");
	diphone_list = g_list_append(diphone_list, "iy-n");
	diphone_list = g_list_append(diphone_list, "n-t");			
	diphone_list = g_list_append(diphone_list, "t-iy");	
	diphone_list = g_list_append(diphone_list, "iy-n");	
	diphone_list = g_list_append(diphone_list, "n-th");	  
    }	
	//twentieth T_W W_EH EH_N N_T T_IY IY_AH AH_TH
	if (g_strcmp0(word,"twentieth")==0) {	
	diphone_list = g_list_append(diphone_list, "t-w");
	diphone_list = g_list_append(diphone_list, "w-eh");
	diphone_list = g_list_append(diphone_list, "eh-n");
	diphone_list = g_list_append(diphone_list, "n-t");			
	diphone_list = g_list_append(diphone_list, "t-iy");	
	diphone_list = g_list_append(diphone_list, "iy-ah");
	diphone_list = g_list_append(diphone_list, "ah-th");  
    }	
	//thirtieth TH_UH UH_R R_T T_IY IY_AH AH_TH
	if (g_strcmp0(word,"thirtieth")==0) {	
	diphone_list = g_list_append(diphone_list, "th-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");
	diphone_list = g_list_append(diphone_list, "r-t");
	diphone_list = g_list_append(diphone_list, "t-iy");			
	diphone_list = g_list_append(diphone_list, "iy-ah");
	diphone_list = g_list_append(diphone_list, "ah-th");	  
    }	
	   
    //------------------------------------------------------------------
    // Months
    //------------------------------------------------------------------
    
    //january JH_AE AE_N N_Y Y_UW UW_EH EH_R R_IY 
    if (g_strcmp0(word,"january")==0) {	
	diphone_list = g_list_append(diphone_list, "jh-ae");
	diphone_list = g_list_append(diphone_list, "ae-n");
	diphone_list = g_list_append(diphone_list, "n-y");
	diphone_list = g_list_append(diphone_list, "y-uw");			
	diphone_list = g_list_append(diphone_list, "uw-eh");	
	diphone_list = g_list_append(diphone_list, "eh-r");			
	diphone_list = g_list_append(diphone_list, "r-iy");	    
    }	   
    //february F_EH EH_B B_Y Y_AH AH_W W_EH EH_R R_IY
    if (g_strcmp0(word,"february")==0) {	
	diphone_list = g_list_append(diphone_list, "f-eh");
	diphone_list = g_list_append(diphone_list, "eh-b");
	diphone_list = g_list_append(diphone_list, "b-y");
	diphone_list = g_list_append(diphone_list, "y-ah");			
	diphone_list = g_list_append(diphone_list, "ah-w");	
	diphone_list = g_list_append(diphone_list, "w-eh");			
	diphone_list = g_list_append(diphone_list, "eh-r");
	diphone_list = g_list_append(diphone_list, "r-iy");	    
    }	
    
    //March M_AA AA_R R_CH CH_PAU
    if (g_strcmp0(word,"march")==0) {
	diphone_list = g_list_append(diphone_list, "m-aa");
	diphone_list = g_list_append(diphone_list, "aa-r");	
	diphone_list = g_list_append(diphone_list, "r-ch");	
	diphone_list = g_list_append(diphone_list, "ch-pau");		  
    }
    
    //april EH_IY IY_P P_R R_AH AH_L
    if (g_strcmp0(word,"april")==0) {	
	diphone_list = g_list_append(diphone_list, "eh-iy");
	diphone_list = g_list_append(diphone_list, "iy-p");
	diphone_list = g_list_append(diphone_list, "p-r");
	diphone_list = g_list_append(diphone_list, "r-ah");			
	diphone_list = g_list_append(diphone_list, "ah-l");		    
    }	
    //may M_EH EH_IY
    if (g_strcmp0(word,"may")==0) {	
	diphone_list = g_list_append(diphone_list, "m-eh");
	diphone_list = g_list_append(diphone_list, "eh-iy");		    
    }	
    //june JH_UW UW_N
    if (g_strcmp0(word,"june")==0) {	
	diphone_list = g_list_append(diphone_list, "jh-uw");
	diphone_list = g_list_append(diphone_list, "uw-n");		    
    }	
    //july JH_UW UW_L L_AA AA_IY
    if (g_strcmp0(word,"july")==0) {	
	diphone_list = g_list_append(diphone_list, "jh-uw");
	diphone_list = g_list_append(diphone_list, "uw-l");
	diphone_list = g_list_append(diphone_list, "l-aa");
	diphone_list = g_list_append(diphone_list, "aa-iy");
    }	
    //august AA_G G_AH AH_S S_T
    if (g_strcmp0(word,"august")==0) {	
	diphone_list = g_list_append(diphone_list, "aa-g");
	diphone_list = g_list_append(diphone_list, "g-ah");
	diphone_list = g_list_append(diphone_list, "ah-s");
	diphone_list = g_list_append(diphone_list, "s-t");
    }	
    //september S_EH EH_P P_T T_EH EH_M M_B B_UH UH_R
    if (g_strcmp0(word,"september")==0) {	
	diphone_list = g_list_append(diphone_list, "s-eh");
	diphone_list = g_list_append(diphone_list, "eh-p");
	diphone_list = g_list_append(diphone_list, "p-t");
	diphone_list = g_list_append(diphone_list, "t-eh");			
	diphone_list = g_list_append(diphone_list, "eh-m");	
	diphone_list = g_list_append(diphone_list, "m-b");			
	diphone_list = g_list_append(diphone_list, "b-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");		    
    }	
    //october AA_K K_T T_AO AO_UH UH_B B_UH UH_R
    if (g_strcmp0(word,"october")==0) {	
	diphone_list = g_list_append(diphone_list, "aa-k");
	diphone_list = g_list_append(diphone_list, "k-t");
	diphone_list = g_list_append(diphone_list, "t-ao");
	diphone_list = g_list_append(diphone_list, "ao-uh");			
	diphone_list = g_list_append(diphone_list, "uh-b");	
	diphone_list = g_list_append(diphone_list, "b-uh");			
	diphone_list = g_list_append(diphone_list, "uh-r");	    
    }	
    //november N_AO AO_UH UH_V V_EH EH_M M_B B_UH UH_R
    if (g_strcmp0(word,"november")==0) {	
	diphone_list = g_list_append(diphone_list, "n-ao");
	diphone_list = g_list_append(diphone_list, "ao-uh");
	diphone_list = g_list_append(diphone_list, "uh-v");
	diphone_list = g_list_append(diphone_list, "v-eh");			
	diphone_list = g_list_append(diphone_list, "eh-m");	
	diphone_list = g_list_append(diphone_list, "m-b");			
	diphone_list = g_list_append(diphone_list, "b-uh");	
	diphone_list = g_list_append(diphone_list, "uh-r");	    
    }	
    //december D_IH IH_S S_EH EH_M M_B B_UH UH_R
    if (g_strcmp0(word,"december")==0) {	
	diphone_list = g_list_append(diphone_list, "d-ih");
	diphone_list = g_list_append(diphone_list, "ih-s");
	diphone_list = g_list_append(diphone_list, "s-eh");
	diphone_list = g_list_append(diphone_list, "eh-m");			
	diphone_list = g_list_append(diphone_list, "m-b");	
	diphone_list = g_list_append(diphone_list, "b-uh");			
	diphone_list = g_list_append(diphone_list, "uh-r");	    
    }	
    
    
    //------------------------------------------------------------------
    // Cardinal Numbers (Time and Event Number)
    //------------------------------------------------------------------
    
    //zero Z_IH IH_R R_AO AO_UH
    if (g_strcmp0(word,"zero")==0) {	
	diphone_list = g_list_append(diphone_list, "z-ih");
	diphone_list = g_list_append(diphone_list, "ih-r");
	diphone_list = g_list_append(diphone_list, "r-ao");
	diphone_list = g_list_append(diphone_list, "ao-uh");
    }	
    
    //one W_AH AH_N
    
    if (g_strcmp0(word,"one")==0) {	
	diphone_list = g_list_append(diphone_list, "w-ah");
	diphone_list = g_list_append(diphone_list, "ah-n");	    
    }	
        
    //two T_UW
    if (g_strcmp0(word,"two")==0) {	
	diphone_list = g_list_append(diphone_list, "t-uw");		    
    }	
    
    //three TH_R R_IY
    if (g_strcmp0(word,"three")==0) {	
	diphone_list = g_list_append(diphone_list, "th-r");
	diphone_list = g_list_append(diphone_list, "r-iy");	    
    }	
    
    //four F_AO AO_R
    if (g_strcmp0(word,"four")==0) {	
	diphone_list = g_list_append(diphone_list, "f-ao");
	diphone_list = g_list_append(diphone_list, "ao-r");		    
    }	
    //five F_AA AA_IY IY_V
    if (g_strcmp0(word,"five")==0) {	
	diphone_list = g_list_append(diphone_list, "f-aa");
	diphone_list = g_list_append(diphone_list, "aa-iy");
	diphone_list = g_list_append(diphone_list, "iy-v");		    
    }
    
    //six S_IH IH_K K_S
     if (g_strcmp0(word,"six")==0) {	
	diphone_list = g_list_append(diphone_list, "s-ih");
	diphone_list = g_list_append(diphone_list, "ih-k");
	diphone_list = g_list_append(diphone_list, "k-s");		    
    }
    //seven S_EH EH_V V_AH AH_N
    if (g_strcmp0(word,"seven")==0) {	
	diphone_list = g_list_append(diphone_list, "s-eh");
	diphone_list = g_list_append(diphone_list, "eh-v");
	diphone_list = g_list_append(diphone_list, "v-ah");	
	diphone_list = g_list_append(diphone_list, "ah-n");		    
    }
    
    //eight EH_IY IY_T
     if (g_strcmp0(word,"eight")==0) {	
	diphone_list = g_list_append(diphone_list, "eh-iy");
	diphone_list = g_list_append(diphone_list, "iy-t");			    
    }
    
    //nine N_AA AA_IY IY_N
     if (g_strcmp0(word,"nine")==0) {	
	diphone_list = g_list_append(diphone_list, "n-aa");
	diphone_list = g_list_append(diphone_list, "aa-iy");
	diphone_list = g_list_append(diphone_list, "iy-n");			    
    }

    //ten T_EH EH_N
     if (g_strcmp0(word,"ten")==0) {	
	diphone_list = g_list_append(diphone_list, "t-eh");
	diphone_list = g_list_append(diphone_list, "eh-n");		    
    }
        
    //eleven IH_L L_EH EH_V V_AH AH_N
    if (g_strcmp0(word,"eleven")==0) {	
	diphone_list = g_list_append(diphone_list, "ih-l");
	diphone_list = g_list_append(diphone_list, "l-eh");
	diphone_list = g_list_append(diphone_list, "eh-v");	
	diphone_list = g_list_append(diphone_list, "v-ah");	
	diphone_list = g_list_append(diphone_list, "ah-n");		    
    }
     
    //twelve T_W W_EH EH_L L_V
    if (g_strcmp0(word,"twelve")==0) {	
	diphone_list = g_list_append(diphone_list, "t-w");
	diphone_list = g_list_append(diphone_list, "w-eh");
	diphone_list = g_list_append(diphone_list, "eh-l");	
	diphone_list = g_list_append(diphone_list, "l-v");
    }	
       
    
    //thirteen TH_UH UH_R R_T T_IY IY_N
    if (g_strcmp0(word,"thirteen")==0) {	
	diphone_list = g_list_append(diphone_list, "th-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");
	diphone_list = g_list_append(diphone_list, "r-t");	
	diphone_list = g_list_append(diphone_list, "t-iy");	
	diphone_list = g_list_append(diphone_list, "iy-n");		    
    }
    //fourteen F_AO AO_R R_T T_IY IY_N
    if (g_strcmp0(word,"fourteen")==0) {	
	diphone_list = g_list_append(diphone_list, "f-ao");
	diphone_list = g_list_append(diphone_list, "ao-r");
	diphone_list = g_list_append(diphone_list, "r-t");	
	diphone_list = g_list_append(diphone_list, "t-iy");	
	diphone_list = g_list_append(diphone_list, "iy-n");		    
    }
        
    //fifteen F_IH IH_F F_T T_IY IY_N
    if (g_strcmp0(word,"fifteen")==0) {	
	diphone_list = g_list_append(diphone_list, "f-ih");
	diphone_list = g_list_append(diphone_list, "ih-f");
	diphone_list = g_list_append(diphone_list, "f-t");	
	diphone_list = g_list_append(diphone_list, "t-iy");	
	diphone_list = g_list_append(diphone_list, "iy-n");		    
    }
        
    //sixteen S_IH IH_K K_S S_T T_IY IY_N
    if (g_strcmp0(word,"sixteen")==0) {	
	diphone_list = g_list_append(diphone_list, "s-ih");
	diphone_list = g_list_append(diphone_list, "ih-k");
	diphone_list = g_list_append(diphone_list, "k-s");	
	diphone_list = g_list_append(diphone_list, "s-t");	
	diphone_list = g_list_append(diphone_list, "t-iy");
	diphone_list = g_list_append(diphone_list, "iy-n");			    
    }
        
    //seventeen S_EH EH_V V_AH AH_N N_T T_IY IY_N
    if (g_strcmp0(word,"seventeen")==0) {	
	diphone_list = g_list_append(diphone_list, "s-eh");
	diphone_list = g_list_append(diphone_list, "eh-v");
	diphone_list = g_list_append(diphone_list, "v-ah");	
	diphone_list = g_list_append(diphone_list, "ah-n");	
	diphone_list = g_list_append(diphone_list, "n-t");
	diphone_list = g_list_append(diphone_list, "t-iy");
	diphone_list = g_list_append(diphone_list, "iy-n");				    
    }
    
    //eighteen EH_IY IY_T T_IY IY_N
    if (g_strcmp0(word,"eighteen")==0) {	
	diphone_list = g_list_append(diphone_list, "eh-iy");
	diphone_list = g_list_append(diphone_list, "iy-t");
	diphone_list = g_list_append(diphone_list, "t-iy");	
	diphone_list = g_list_append(diphone_list, "iy-n");						    
    }
    
    //nineteen N_AA AA_IY IY_N N_T T_IY IY_N
    if (g_strcmp0(word,"nineteen")==0) {	
	diphone_list = g_list_append(diphone_list, "n-aa");
	diphone_list = g_list_append(diphone_list, "aa-iy");
	diphone_list = g_list_append(diphone_list, "iy-n");	
	diphone_list = g_list_append(diphone_list, "n-t");	
	diphone_list = g_list_append(diphone_list, "t-iy");
	diphone_list = g_list_append(diphone_list, "iy-n");
	//diphone_list = g_list_append(diphone_list, "iy-n");				    
    }	
    
    //twenty T_W W_EH EH_N N_T T_IY
	if (g_strcmp0(word,"twenty")==0) {	
	diphone_list = g_list_append(diphone_list, "t-w");
	diphone_list = g_list_append(diphone_list, "w-eh");
	diphone_list = g_list_append(diphone_list, "eh-n");
	diphone_list = g_list_append(diphone_list, "n-t");			
	diphone_list = g_list_append(diphone_list, "t-iy");	  
    }	
    
    //thirty TH_UH UH_R R_D D_IY
    if (g_strcmp0(word,"thirty")==0) {	
	diphone_list = g_list_append(diphone_list, "th-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");
	diphone_list = g_list_append(diphone_list, "r-d");
	diphone_list = g_list_append(diphone_list, "d-iy");	
    }	
    
    //forty F_AO AO_R R_T T_IY
    if (g_strcmp0(word,"forty")==0) {	
	diphone_list = g_list_append(diphone_list, "f-ao");
	diphone_list = g_list_append(diphone_list, "ao-r");
	diphone_list = g_list_append(diphone_list, "r-t");				
	diphone_list = g_list_append(diphone_list, "t-iy");	  
    }	
    
    //fifty F_IH IH_F F_T T_IY
    if (g_strcmp0(word,"fifty")==0) {	
	diphone_list = g_list_append(diphone_list, "f-ih");
	diphone_list = g_list_append(diphone_list, "ih-f");
	diphone_list = g_list_append(diphone_list, "f-t");				
	diphone_list = g_list_append(diphone_list, "t-iy");	  
    }	
    
    
    //------------------------------------------------------------------
    // Event Words
    //------------------------------------------------------------------
    
    //template
	//if (g_strcmp0(word,"")==0) {	
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	    
    //}	
    
    
    
    //------------------------------------------------------------------
    // A Words
    //------------------------------------------------------------------
    
    //if (g_strcmp0(word,"")==0) {	
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	    
    //}	
    
    //all AO_L
    if (g_strcmp0(word,"all")==0) {	
	diphone_list = g_list_append(diphone_list, "ao-l");
	}
    
    //and AH_N N_D
    if (g_strcmp0(word,"and")==0) {	
	diphone_list = g_list_append(diphone_list, "ah-n");
	diphone_list = g_list_append(diphone_list, "n-d");
     }
    
    //anniversary AE_N N_AH AH_V V_UH UH_R R_S S_UH UH_R R_IY    	
	if (g_strcmp0(word,"anniversary")==0) {	
	diphone_list = g_list_append(diphone_list, "ae-n");
	diphone_list = g_list_append(diphone_list, "n-ah");
	diphone_list = g_list_append(diphone_list, "ah-v");
	diphone_list = g_list_append(diphone_list, "v-uh");			
	diphone_list = g_list_append(diphone_list, "uh-r");	
	diphone_list = g_list_append(diphone_list, "r-s");			
	diphone_list = g_list_append(diphone_list, "s-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");	
	diphone_list = g_list_append(diphone_list, "r-iy");		    
    }	
     
	//accounts AH_K K_AA AA_UH UH_N N_T T_S
	if (g_strcmp0(word,"accounts")==0) {	
	diphone_list = g_list_append(diphone_list, "ah-k");
	diphone_list = g_list_append(diphone_list, "k-aa");
	diphone_list = g_list_append(diphone_list, "aa-uh");
	diphone_list = g_list_append(diphone_list, "uh-n");			
	diphone_list = g_list_append(diphone_list, "n-t");	
	diphone_list = g_list_append(diphone_list, "t-s");
    }	
	
	//action AE_K K_SH SH_AH AH_N
	if (g_strcmp0(word,"action")==0) {	
	diphone_list = g_list_append(diphone_list, "ae-k");
	diphone_list = g_list_append(diphone_list, "k-sh");
	diphone_list = g_list_append(diphone_list, "sh-ah");
	diphone_list = g_list_append(diphone_list, "ah-n");	
    }	
	
	//activity AE_K K_T T_IH IH_V V_AH AH_T T_IY
    if (g_strcmp0(word,"activity")==0) {	
	diphone_list = g_list_append(diphone_list, "ae-k");
	diphone_list = g_list_append(diphone_list, "k-t");
	diphone_list = g_list_append(diphone_list, "t-ih");
	diphone_list = g_list_append(diphone_list, "ih--v");			
	diphone_list = g_list_append(diphone_list, "v-ah");	
	diphone_list = g_list_append(diphone_list, "ah-t");			
	diphone_list = g_list_append(diphone_list, "t-iy");	    
    }	
   
    //allotment AH_L L_AA AA_T T_M M_AH AH_N N_T
    if (g_strcmp0(word,"allotment")==0) {	
	diphone_list = g_list_append(diphone_list, "ah-l");
	diphone_list = g_list_append(diphone_list, "l-aa");
	diphone_list = g_list_append(diphone_list, "aa-t");
	diphone_list = g_list_append(diphone_list, "t-m");			
	diphone_list = g_list_append(diphone_list, "m-ah");	
	diphone_list = g_list_append(diphone_list, "ah-n");			
	diphone_list = g_list_append(diphone_list, "n-t");	    
    }	
   
    //appointment AH_P P_AO AO_IY IY_N N_T T_M M_AH AH_N N_T
    if (g_strcmp0(word,"appointment")==0) {	
	diphone_list = g_list_append(diphone_list, "ah-p");
	diphone_list = g_list_append(diphone_list, "p-ao");
	diphone_list = g_list_append(diphone_list, "ao-iy");
	diphone_list = g_list_append(diphone_list, "iy-n");			
	diphone_list = g_list_append(diphone_list, "n-t");	
	diphone_list = g_list_append(diphone_list, "t-m");			
	diphone_list = g_list_append(diphone_list, "m-ah");	
	diphone_list = g_list_append(diphone_list, "ah-n");
	diphone_list = g_list_append(diphone_list, "n-t");    
    }	
   
  
    //agent EH_IY IY_JH JH_AH AH_N N_T   
    if (g_strcmp0(word,"agent")==0) {	
	diphone_list = g_list_append(diphone_list, "eh-iy");
	diphone_list = g_list_append(diphone_list, "iy-jh");
	diphone_list = g_list_append(diphone_list, "jh-ah");
	diphone_list = g_list_append(diphone_list, "ah-n");
	diphone_list = g_list_append(diphone_list, "n-t");
    }	
    
    
   
    //alert AH_L L_UH UH_R R_T
    if (g_strcmp0(word,"alert")==0) {	
	diphone_list = g_list_append(diphone_list, "ah-l");
	diphone_list = g_list_append(diphone_list, "l-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");
	diphone_list = g_list_append(diphone_list, "r-t");
    }	
    
    
    //ambulance AE_M M_B B_Y Y_AH AH_L L_AH AH_N N_S
    if (g_strcmp0(word,"ambulance")==0) {	
	diphone_list = g_list_append(diphone_list, "ae-m");
	diphone_list = g_list_append(diphone_list, "m-b");
	diphone_list = g_list_append(diphone_list, "b-y");
	diphone_list = g_list_append(diphone_list, "y-ah");			
	diphone_list = g_list_append(diphone_list, "ah-l");	
	diphone_list = g_list_append(diphone_list, "l-ah");			
	diphone_list = g_list_append(diphone_list, "ah-n");	
	diphone_list = g_list_append(diphone_list, "n-s");	   
    }	
    
    //airport EH_R R_P P_AO AO_R R_T
    if (g_strcmp0(word,"airport")==0) {	
	diphone_list = g_list_append(diphone_list, "eh-r");
	diphone_list = g_list_append(diphone_list, "r-p");
	diphone_list = g_list_append(diphone_list, "p-ao");
	diphone_list = g_list_append(diphone_list, "ao-r");			
	diphone_list = g_list_append(diphone_list, "r-t");
    }	
    
    //assessment AH_S S_EH EH_S S_M M_AH AH_N N_T
    if (g_strcmp0(word,"assessment")==0) {	
	diphone_list = g_list_append(diphone_list, "ah-s");
	diphone_list = g_list_append(diphone_list, "s-eh");
	diphone_list = g_list_append(diphone_list, "eh-s");
	diphone_list = g_list_append(diphone_list, "s-m");			
	diphone_list = g_list_append(diphone_list, "m-ah");	
	diphone_list = g_list_append(diphone_list, "ah-n");			
	diphone_list = g_list_append(diphone_list, "n-t");
    }	
     
    
    //assets AE_S S_EH EH_T T_S
    if (g_strcmp0(word,"assets")==0) {	
	diphone_list = g_list_append(diphone_list, "ae-s");
	diphone_list = g_list_append(diphone_list, "s-eh");
	diphone_list = g_list_append(diphone_list, "eh-t");
	diphone_list = g_list_append(diphone_list, "t-s");	
    }	
    
    //assistant AH_S S_IH IH_S S_T T_AH AH_N N_T
    if (g_strcmp0(word,"assistant")==0) {	
	diphone_list = g_list_append(diphone_list, "ah-s");
	diphone_list = g_list_append(diphone_list, "s-ih");
	diphone_list = g_list_append(diphone_list, "ih-s");
	diphone_list = g_list_append(diphone_list, "s-t");			
	diphone_list = g_list_append(diphone_list, "t-ah");	
	diphone_list = g_list_append(diphone_list, "ah-n");			
	diphone_list = g_list_append(diphone_list, "n-t");
    }	
    
    
    //award AH_W W_AO AO_R R_D
    if (g_strcmp0(word,"award")==0) {	
	diphone_list = g_list_append(diphone_list, "ah-w");
	diphone_list = g_list_append(diphone_list, "w-ao");
	diphone_list = g_list_append(diphone_list, "ao-r");
	diphone_list = g_list_append(diphone_list, "r-d");
    }	
    
    //away AH_W W_EH EH_IY
    if (g_strcmp0(word,"away")==0) {	
	diphone_list = g_list_append(diphone_list, "ah-w");
	diphone_list = g_list_append(diphone_list, "w-eh");
	diphone_list = g_list_append(diphone_list, "eh-iy");
    }	
    
    
    //------------------------------------------------------------------
    // B Words
    //------------------------------------------------------------------
    //if (g_strcmp0(word,"")==0) {	
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	    
    //}	
    
    
    //birthday B_UH UH_R R_TH TH_D D_EH EH_IY
    if (g_strcmp0(word,"birthday")==0) {	
	diphone_list = g_list_append(diphone_list, "b-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");
	diphone_list = g_list_append(diphone_list, "r-th");
	diphone_list = g_list_append(diphone_list, "th-d");			
	diphone_list = g_list_append(diphone_list, "d-eh");	
	diphone_list = g_list_append(diphone_list, "eh-iy");
    }
    
    //bank B_AE AE_NG NG_K	
    if (g_strcmp0(word,"bank")==0) {	
	diphone_list = g_list_append(diphone_list, "b-ae");
	diphone_list = g_list_append(diphone_list, "ae-ng");
	diphone_list = g_list_append(diphone_list, "ng-k");	    
    }	
    
    //banquet B_AE AE_NG NG_K K_W W_AH AH_T
    if (g_strcmp0(word,"banquet")==0) {	
	diphone_list = g_list_append(diphone_list, "b-ae");
	diphone_list = g_list_append(diphone_list, "ae-ng");
	diphone_list = g_list_append(diphone_list, "ng-k");
	diphone_list = g_list_append(diphone_list, "k-w");			
	diphone_list = g_list_append(diphone_list, "w-ah");	
	diphone_list = g_list_append(diphone_list, "ah-t");	
    }	
    
    //barber B_AA AA_R R_B B_UH UH_R
    if (g_strcmp0(word,"barber")==0) {	
	diphone_list = g_list_append(diphone_list, "b-aa");
	diphone_list = g_list_append(diphone_list, "aa-r");
	diphone_list = g_list_append(diphone_list, "r-b");
	diphone_list = g_list_append(diphone_list, "b-uh");			
	diphone_list = g_list_append(diphone_list, "uh-r");	
    }	
    
    //bill B_IH IH_L
    if (g_strcmp0(word,"bill")==0) {	
	diphone_list = g_list_append(diphone_list, "b-ih");
	diphone_list = g_list_append(diphone_list, "ih-l");
	 }	
    
    //book B_UH UH_K
    if (g_strcmp0(word,"book")==0) {	
	diphone_list = g_list_append(diphone_list, "b-uh");
	diphone_list = g_list_append(diphone_list, "uh-k");	    
    }	
    
    
    //builder B_IH IH_L L_D D_UH UH_R
    if (g_strcmp0(word,"builder")==0) {	
	diphone_list = g_list_append(diphone_list, "b-ih");
	diphone_list = g_list_append(diphone_list, "ih-l");
	diphone_list = g_list_append(diphone_list, "l-d");
	diphone_list = g_list_append(diphone_list, "d-uh");			
	diphone_list = g_list_append(diphone_list, "uh-r");	
    }	
    
    //brother B_R R_AH AH_DH DH_UH UH_R
    if (g_strcmp0(word,"brother")==0) {	
	diphone_list = g_list_append(diphone_list, "b-r");
	diphone_list = g_list_append(diphone_list, "r-ah");
	diphone_list = g_list_append(diphone_list, "ah-dh");
	diphone_list = g_list_append(diphone_list, "dh-uh");			
	diphone_list = g_list_append(diphone_list, "uh-r");	
    }	
    
    
    //------------------------------------------------------------------
    // C Words
    //------------------------------------------------------------------
    //if (g_strcmp0(word,"")==0) {	
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	    
    //}	
    
    //calendar K_AE AE_L L_AH AH_N N_D D_UH UH_R
    if (g_strcmp0(word,"calendar")==0) {	
	diphone_list = g_list_append(diphone_list, "k-ae");
	diphone_list = g_list_append(diphone_list, "ae-l");
	diphone_list = g_list_append(diphone_list, "l-ah");
	diphone_list = g_list_append(diphone_list, "ah-n");			
	diphone_list = g_list_append(diphone_list, "n-d");	
	diphone_list = g_list_append(diphone_list, "d-uh");			
	diphone_list = g_list_append(diphone_list, "uh-r");	    
    }	
    
    //cancel K_AE AE_N N_S S_AH AH_L
    if (g_strcmp0(word,"cancel")==0) {	
	diphone_list = g_list_append(diphone_list, "k-ae");
	diphone_list = g_list_append(diphone_list, "ae-n");
	diphone_list = g_list_append(diphone_list, "n-s");
	diphone_list = g_list_append(diphone_list, "s-ah");			
	diphone_list = g_list_append(diphone_list, "ah-l");	
    }	
    
    //cancelled K_AE AE_N N_S S_AH AH_L L_D
    if (g_strcmp0(word,"cancelled")==0) {	
	diphone_list = g_list_append(diphone_list, "k-ae");
	diphone_list = g_list_append(diphone_list, "ae-n");
	diphone_list = g_list_append(diphone_list, "n-s");
	diphone_list = g_list_append(diphone_list, "s-ah");			
	diphone_list = g_list_append(diphone_list, "ah-l");	
	diphone_list = g_list_append(diphone_list, "l-d");
    }	
    
    
    //ceremony S_EH EH_R R_AH AH_M M_AO AO_UH UH_N N_IY
    if (g_strcmp0(word,"cermony")==0) {	
	diphone_list = g_list_append(diphone_list, "s-eh");
	diphone_list = g_list_append(diphone_list, "eh-r");
	diphone_list = g_list_append(diphone_list, "r-ah");
	diphone_list = g_list_append(diphone_list, "ah-m");			
	diphone_list = g_list_append(diphone_list, "m-ao");	
	diphone_list = g_list_append(diphone_list, "ao-uh");			
	diphone_list = g_list_append(diphone_list, "uh-n");
	diphone_list = g_list_append(diphone_list, "n-iy");	    
    }	
    
    
    //car K_AA AA_R
    if (g_strcmp0(word,"car")==0) {	
	diphone_list = g_list_append(diphone_list, "k-aa");
	diphone_list = g_list_append(diphone_list, "aa-r");
    }	
    
    
    
    //caravan K_AE AE_R R_AH AH_V V_AE AE_N
    if (g_strcmp0(word,"caravan")==0) {	
	diphone_list = g_list_append(diphone_list, "k-ae");
	diphone_list = g_list_append(diphone_list, "ae-r");
	diphone_list = g_list_append(diphone_list, "r-ah");
	diphone_list = g_list_append(diphone_list, "ah-v");			
	diphone_list = g_list_append(diphone_list, "v-ae");	
	diphone_list = g_list_append(diphone_list, "ae-n");
    }	
    
    //celebrate S_EH EH_L L_AH AH_B B_R R_EH EH_IY IY_T
    if (g_strcmp0(word,"celebrate")==0) {	
	diphone_list = g_list_append(diphone_list, "s-eh");
	diphone_list = g_list_append(diphone_list, "eh-l");
	diphone_list = g_list_append(diphone_list, "l-ah");
	diphone_list = g_list_append(diphone_list, "ah-b");			
	diphone_list = g_list_append(diphone_list, "b-r");	
	diphone_list = g_list_append(diphone_list, "r-eh");			
	diphone_list = g_list_append(diphone_list, "eh-iy");
	diphone_list = g_list_append(diphone_list, "iy-t");	    
    }	
    
    
    //celebration S_EH EH_L L_AH AH_B B_R R_EH EH_IY IY_SH SH_AH AH_N
    if (g_strcmp0(word,"celebration")==0) {	
	diphone_list = g_list_append(diphone_list, "s-eh");
	diphone_list = g_list_append(diphone_list, "eh-l");
	diphone_list = g_list_append(diphone_list, "l-ah");
	diphone_list = g_list_append(diphone_list, "ah-b");			
	diphone_list = g_list_append(diphone_list, "b-r");	
	diphone_list = g_list_append(diphone_list, "r-eh");			
	diphone_list = g_list_append(diphone_list, "eh-iy");
	diphone_list = g_list_append(diphone_list, "iy-sh");
	diphone_list = g_list_append(diphone_list, "sh-ah");
	diphone_list = g_list_append(diphone_list, "ah-n");	    
    }	
    
    //charity CH_EH EH_R R_IH IH_T T_IY
    if (g_strcmp0(word,"charity")==0) {	
	diphone_list = g_list_append(diphone_list, "ch-eh");
	diphone_list = g_list_append(diphone_list, "eh-r");
	diphone_list = g_list_append(diphone_list, "r-ih");
	diphone_list = g_list_append(diphone_list, "ih-t");			
	diphone_list = g_list_append(diphone_list, "t-iy");	
    }	
    
    //clinic K_L L_IH IH_N N_IH IH_K
    if (g_strcmp0(word,"clinic")==0) {	
	diphone_list = g_list_append(diphone_list, "k-l");
	diphone_list = g_list_append(diphone_list, "l-ih");
	diphone_list = g_list_append(diphone_list, "ih-n");
	diphone_list = g_list_append(diphone_list, "n-ih");			
	diphone_list = g_list_append(diphone_list, "ih-k");	
    }	
    
    //computer K_AH AH_M M_P P_Y Y_UW UW_T T_UH UH_R
    if (g_strcmp0(word,"computer")==0) {	
	diphone_list = g_list_append(diphone_list, "k-ah");
	diphone_list = g_list_append(diphone_list, "ah-m");
	diphone_list = g_list_append(diphone_list, "m-p");
	diphone_list = g_list_append(diphone_list, "p-y");			
	diphone_list = g_list_append(diphone_list, "y-uw");	
	diphone_list = g_list_append(diphone_list, "uw-t");			
	diphone_list = g_list_append(diphone_list, "t-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");		    
    }	
    
    //credit K_R R_EH EH_D D_AH AH_T
    if (g_strcmp0(word,"credit")==0) {	
	diphone_list = g_list_append(diphone_list, "k-r");
	diphone_list = g_list_append(diphone_list, "r-eh");
	diphone_list = g_list_append(diphone_list, "eh-d");
	diphone_list = g_list_append(diphone_list, "d-ah");			
	diphone_list = g_list_append(diphone_list, "ah-t");	
    }	
    
    //card K_AA AA_R R_D
    if (g_strcmp0(word,"card")==0) {	
	diphone_list = g_list_append(diphone_list, "k-aa");
	diphone_list = g_list_append(diphone_list, "aa-r");
	diphone_list = g_list_append(diphone_list, "r-d");
	}	
    
    //check CH_EH EH_K
    if (g_strcmp0(word,"check")==0) {	
	diphone_list = g_list_append(diphone_list, "ch-eh");
	diphone_list = g_list_append(diphone_list, "eh-k");
	 }	
    
    //christmas K_R R_IH IH_S S_M M_AH AH_S
    if (g_strcmp0(word,"christmas")==0) {	
	diphone_list = g_list_append(diphone_list, "k-r");
	diphone_list = g_list_append(diphone_list, "r-ih");
	diphone_list = g_list_append(diphone_list, "ih-s");
	diphone_list = g_list_append(diphone_list, "s-m");			
	diphone_list = g_list_append(diphone_list, "m-ah");	
	diphone_list = g_list_append(diphone_list, "ah-s");
    }	
    
    //code K_AO AO_UH UH_D
    if (g_strcmp0(word,"code")==0) {	
	diphone_list = g_list_append(diphone_list, "k-ao");
	diphone_list = g_list_append(diphone_list, "ao-uh");
	diphone_list = g_list_append(diphone_list, "uh-d");		    
    }	
    
    //cook K_UH UH_K
    if (g_strcmp0(word,"cook")==0) {	
	diphone_list = g_list_append(diphone_list, "k-uh");
	diphone_list = g_list_append(diphone_list, "uh-k");
	}	
    
    //cooking K_UH UH_K K_IH IH_NG
    if (g_strcmp0(word,"cooking")==0) {	
	diphone_list = g_list_append(diphone_list, "k-uh");
	diphone_list = g_list_append(diphone_list, "uh-k");
	diphone_list = g_list_append(diphone_list, "k-ih");
	diphone_list = g_list_append(diphone_list, "ih-ng");
    }	
    
    //contact K_AA AA_N N_T T_AE AE_K K_T
    if (g_strcmp0(word,"contact")==0) {	
	diphone_list = g_list_append(diphone_list, "k-aa");
	diphone_list = g_list_append(diphone_list, "aa-n");
	diphone_list = g_list_append(diphone_list, "n-t");
	diphone_list = g_list_append(diphone_list, "t-ae");			
	diphone_list = g_list_append(diphone_list, "ae-k");	
	diphone_list = g_list_append(diphone_list, "k-t");
    }	
    
    //cricket K_R R_IH IH_K K_AH AH_T
    if (g_strcmp0(word,"cricket")==0) {	
	diphone_list = g_list_append(diphone_list, "k-r");
	diphone_list = g_list_append(diphone_list, "r-ih");
	diphone_list = g_list_append(diphone_list, "ih-k");
	diphone_list = g_list_append(diphone_list, "k-ah");			
	diphone_list = g_list_append(diphone_list, "ah-t");	
    }	
    
    //critical K_R R_IH IH_T T_IH IH_K K_AH AH_L
    if (g_strcmp0(word,"critical")==0) {	
	diphone_list = g_list_append(diphone_list, "k-r");
	diphone_list = g_list_append(diphone_list, "r-ih");
	diphone_list = g_list_append(diphone_list, "ih-t");
	diphone_list = g_list_append(diphone_list, "t-ih");			
	diphone_list = g_list_append(diphone_list, "ih-k");	
	diphone_list = g_list_append(diphone_list, "k-ah");			
	diphone_list = g_list_append(diphone_list, "ah-l");	    
    }	
    
    //cycle S_AA AA_IY IY_K K_AH AH_L
    if (g_strcmp0(word,"cycle")==0) {	
	diphone_list = g_list_append(diphone_list, "s-aa");
	diphone_list = g_list_append(diphone_list, "aa-iy");
	diphone_list = g_list_append(diphone_list, "iy-k");
	diphone_list = g_list_append(diphone_list, "k-ah");			
	diphone_list = g_list_append(diphone_list, "ah-l");	
    }	
    
    
    //------------------------------------------------------------------
    // D Words
    //------------------------------------------------------------------
    //day D_EH EH_IY (default)
	if (g_strcmp0(word,"day")==0) {	
	diphone_list = g_list_append(diphone_list, "d-eh");
	diphone_list = g_list_append(diphone_list, "eh-iy");
    }
    
    //delivery D_IH IH_L L_IH IH_V V_UH UH_R R_IY
    if (g_strcmp0(word,"delivery")==0) {	
	diphone_list = g_list_append(diphone_list, "d-ih");
	diphone_list = g_list_append(diphone_list, "ih-l");
	diphone_list = g_list_append(diphone_list, "l-ih");
	diphone_list = g_list_append(diphone_list, "ih-v");			
	diphone_list = g_list_append(diphone_list, "v-uh");	
	diphone_list = g_list_append(diphone_list, "uh-r");			
	diphone_list = g_list_append(diphone_list, "r-iy");	    
    }	
    
    //dentist D_EH EH_N N_T T_AH AH_S S_T
    if (g_strcmp0(word,"dentist")==0) {	
	diphone_list = g_list_append(diphone_list, "d-eh");
	diphone_list = g_list_append(diphone_list, "eh-n");
	diphone_list = g_list_append(diphone_list, "n-t");
	diphone_list = g_list_append(diphone_list, "t-ah");			
	diphone_list = g_list_append(diphone_list, "ah-s");	
	diphone_list = g_list_append(diphone_list, "s-t");	
    }	
    
    //development D_IH IH_V V_EH EH_L L_AH AH_P P_M M_AH AH_N N_T
    if (g_strcmp0(word,"development")==0) {	
	diphone_list = g_list_append(diphone_list, "d-ih");
	diphone_list = g_list_append(diphone_list, "ih-v");
	diphone_list = g_list_append(diphone_list, "v-eh");
	diphone_list = g_list_append(diphone_list, "eh-l");			
	diphone_list = g_list_append(diphone_list, "l-ah");	
	diphone_list = g_list_append(diphone_list, "ah-p");			
	diphone_list = g_list_append(diphone_list, "p-m");
	diphone_list = g_list_append(diphone_list, "m-ah");	
	diphone_list = g_list_append(diphone_list, "ah-n");	
	diphone_list = g_list_append(diphone_list, "n-t");		    
    }	
    
    //doctor D_AA AA_K K_T T_UH UH_R
    if (g_strcmp0(word,"doctor")==0) {	
	diphone_list = g_list_append(diphone_list, "d-aa");
	diphone_list = g_list_append(diphone_list, "aa-k");
	diphone_list = g_list_append(diphone_list, "k-t");
	diphone_list = g_list_append(diphone_list, "t-uh");			
	diphone_list = g_list_append(diphone_list, "uh-r");		    
    }	
      
    //date D_EH EH_IY IY_T
    if (g_strcmp0(word,"date")==0) {	
	diphone_list = g_list_append(diphone_list, "d-eh");
	diphone_list = g_list_append(diphone_list, "eh-iy");
	diphone_list = g_list_append(diphone_list, "iy-t");
	}	
    
    //deadline D_EH EH_D D_L L_AA AA_IY IY_N
    if (g_strcmp0(word,"deadline")==0) {	
	diphone_list = g_list_append(diphone_list, "d-eh");
	diphone_list = g_list_append(diphone_list, "eh-d");
	diphone_list = g_list_append(diphone_list, "d-l");
	diphone_list = g_list_append(diphone_list, "l-aa");			
	diphone_list = g_list_append(diphone_list, "aa-iy");	
	diphone_list = g_list_append(diphone_list, "iy-n");	
    }	
   
    //------------------------------------------------------------------
    // E Words
    //------------------------------------------------------------------
   //if (g_strcmp0(word,"")==0) {	
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	    
    //}	
   //event IH_V V_EH EH_N N_T   
   if (g_strcmp0(word,"event")==0) {	
	diphone_list = g_list_append(diphone_list, "ih-v");
	diphone_list = g_list_append(diphone_list, "v-eh");
	diphone_list = g_list_append(diphone_list, "eh-n");
	diphone_list = g_list_append(diphone_list, "n-t");	
    }	
    
   //events IH_V V_EH EH_N N_T T_S   
    if (g_strcmp0(word,"events")==0) {	
	diphone_list = g_list_append(diphone_list, "ih-v");
	diphone_list = g_list_append(diphone_list, "v-eh");
	diphone_list = g_list_append(diphone_list, "eh-n");
	diphone_list = g_list_append(diphone_list, "n-t");			
	diphone_list = g_list_append(diphone_list, "t-s");			    
    }	
   
   //easter IY_S S_T T_UH UH_R
   if (g_strcmp0(word,"easter")==0) {	
	diphone_list = g_list_append(diphone_list, "iy-s");
	diphone_list = g_list_append(diphone_list, "s-t");
	diphone_list = g_list_append(diphone_list, "t-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");	
    }	
   
   //energy EH_N N_UH UH_R R_JH JH_IY
   if (g_strcmp0(word,"energy")==0) {	
	diphone_list = g_list_append(diphone_list, "en-h");
	diphone_list = g_list_append(diphone_list, "n-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");
	diphone_list = g_list_append(diphone_list, "r-jh");			
	diphone_list = g_list_append(diphone_list, "jh-iy");
    }	
   //estate IH_S S_T T_EH EH_IY IY_T
   if (g_strcmp0(word,"estate")==0) {	
	diphone_list = g_list_append(diphone_list, "ih-s");
	diphone_list = g_list_append(diphone_list, "s-t");
	diphone_list = g_list_append(diphone_list, "t-eh");
	diphone_list = g_list_append(diphone_list, "eh-iy");			
	diphone_list = g_list_append(diphone_list, "iy-t");			    
    }	
   
   //entry EH_N N_T T_R R_IY
    if (g_strcmp0(word,"entry")==0) {	
	diphone_list = g_list_append(diphone_list, "eh-n");
	diphone_list = g_list_append(diphone_list, "n-t");
	diphone_list = g_list_append(diphone_list, "t-r");
	diphone_list = g_list_append(diphone_list, "r-iy");			
			    
    }	
   //------------------------------------------------------------------
   // F Words
   //------------------------------------------------------------------
    //if (g_strcmp0(word,"")==0) {	
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	    
    //}	
    
    
    //family F_AE AE_M M_AH AH_L L_IY
    if (g_strcmp0(word,"family")==0) {	
	diphone_list = g_list_append(diphone_list, "f-ae");
	diphone_list = g_list_append(diphone_list, "ae-m");
	diphone_list = g_list_append(diphone_list, "m-ah");
	diphone_list = g_list_append(diphone_list, "ah-l");			
	diphone_list = g_list_append(diphone_list, "l-iy");			    
    }	
        
    //father F_AA AA_DH DH_UH UH_R
     if (g_strcmp0(word,"father")==0) {	
	diphone_list = g_list_append(diphone_list, "f-aa");
	diphone_list = g_list_append(diphone_list, "aa-dh");
	diphone_list = g_list_append(diphone_list, "dh-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");	
    }	
        
    //fathers F_AA AA_DH DH_UH UH_R R_Z
     if (g_strcmp0(word,"fathers")==0) {	
	diphone_list = g_list_append(diphone_list, "f-aa");
	diphone_list = g_list_append(diphone_list, "aa-dh");
	diphone_list = g_list_append(diphone_list, "dh-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");			
	diphone_list = g_list_append(diphone_list, "r-z");			    
    }	
    
    //film F_IH IH_L L_M
    if (g_strcmp0(word,"film")==0) {	
	diphone_list = g_list_append(diphone_list, "f-ih");
	diphone_list = g_list_append(diphone_list, "ih-l");
	diphone_list = g_list_append(diphone_list, "l-m");	    
    }	
    
    //food F_UW UW_D
     if (g_strcmp0(word,"food")==0) {	
	diphone_list = g_list_append(diphone_list, "f-uw");
	diphone_list = g_list_append(diphone_list, "uw-d");		    
    }	
   
    //football F_UH UH_T T_B B_AO AO_L
    if (g_strcmp0(word,"football")==0) {	
	diphone_list = g_list_append(diphone_list, "f-uh");
	diphone_list = g_list_append(diphone_list, "uh-t");
	diphone_list = g_list_append(diphone_list, "t-b");
	diphone_list = g_list_append(diphone_list, "b-ao");			
	diphone_list = g_list_append(diphone_list, "ao-l");
    }	
        
    //friend F_R R_EH EH_N N_D    
    if (g_strcmp0(word,"friend")==0) {	
	diphone_list = g_list_append(diphone_list, "f-r");
	diphone_list = g_list_append(diphone_list, "r-eh");
	diphone_list = g_list_append(diphone_list, "eh-n");
	diphone_list = g_list_append(diphone_list, "n-d");	
    }	
       
    //funeral F_Y Y_UW UW_N N_UH UH_R R_AH AH_L
    if (g_strcmp0(word,"funeral")==0) {	
	diphone_list = g_list_append(diphone_list, "f-y");
	diphone_list = g_list_append(diphone_list, "y-uw");
	diphone_list = g_list_append(diphone_list, "uw-n");
	diphone_list = g_list_append(diphone_list, "n-uh");			
	diphone_list = g_list_append(diphone_list, "uh-r");	
	diphone_list = g_list_append(diphone_list, "r-ah");			
	diphone_list = g_list_append(diphone_list, "ah-l");	    
    }	
   
   //------------------------------------------------------------------
    // G Words
    //------------------------------------------------------------------
    //garden G_AA AA_R R_D D_AH AH_N
    if (g_strcmp0(word,"garden")==0) {	
	diphone_list = g_list_append(diphone_list, "g-aa");
	diphone_list = g_list_append(diphone_list, "aa-r");
	diphone_list = g_list_append(diphone_list, "r-d");
	diphone_list = g_list_append(diphone_list, "d-ah");			
	diphone_list = g_list_append(diphone_list, "ah-n");			    
    }	
    
    //gas G_AE AE_S
    if (g_strcmp0(word,"gas")==0) {	
	diphone_list = g_list_append(diphone_list, "g-ae");
	diphone_list = g_list_append(diphone_list, "ae-s");	    
    }	
    
    //go G_AO AO_UH
    if (g_strcmp0(word,"go")==0) {	
	diphone_list = g_list_append(diphone_list, "g-ao");
	diphone_list = g_list_append(diphone_list, "ao-uh");		    
    }	
    //good G_UH UH_D
    if (g_strcmp0(word,"good")==0) {	
	diphone_list = g_list_append(diphone_list, "g-uh");
	diphone_list = g_list_append(diphone_list, "uh-d");		    
    }
    //grow G_R R_AO AO_UH
    if (g_strcmp0(word,"grow")==0) {	
	diphone_list = g_list_append(diphone_list, "g-r");
	diphone_list = g_list_append(diphone_list, "r-ao");
	diphone_list = g_list_append(diphone_list, "ao-uh");			    
    }
    
    //------------------------------------------------------------------
    // H Words
    //------------------------------------------------------------------
    //HELLO  HH AH0 L OW1
    //hello HH_AH AH_L L_AO AO_UH
	if (g_strcmp0(word,"hello")==0) {	
	//diphone_list = g_list_append(diphone_list, "hh-ah");	
	//diphone_list = g_list_append(diphone_list, "l-ow");
	diphone_list = g_list_append(diphone_list, "hh-ah");
	diphone_list = g_list_append(diphone_list, "ah-l");
	diphone_list = g_list_append(diphone_list, "l-ao");		
	diphone_list = g_list_append(diphone_list, "ao-uh");	  
    }
    
    //hairdressers HH_EH EH_R R_D D_R R_EH EH_S S_UH UH_R R_Z
    if (g_strcmp0(word,"hairdressers")==0) {	
	diphone_list = g_list_append(diphone_list, "hh-eh");
	diphone_list = g_list_append(diphone_list, "eh-r");
	diphone_list = g_list_append(diphone_list, "r-d");
	diphone_list = g_list_append(diphone_list, "d-r");			
	diphone_list = g_list_append(diphone_list, "r-eh");	
	diphone_list = g_list_append(diphone_list, "eh-s");			
	diphone_list = g_list_append(diphone_list, "s-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");	
	diphone_list = g_list_append(diphone_list, "r-z");		    
    }	
    
    //health HH_EH EH_L L_TH
    if (g_strcmp0(word,"health")==0) {	
	diphone_list = g_list_append(diphone_list, "hh-eh");
	diphone_list = g_list_append(diphone_list, "eh-l");
	diphone_list = g_list_append(diphone_list, "l-th");	    
    }	
   
    
    //heating HH_IY IY_T T_IH IH_NG
    if (g_strcmp0(word,"heating")==0) {	
	diphone_list = g_list_append(diphone_list, "hh-iy");
	diphone_list = g_list_append(diphone_list, "iy-t");
	diphone_list = g_list_append(diphone_list, "t-ih");
	diphone_list = g_list_append(diphone_list, "ih-hg");
    }	
      
    //high HH_AA AA_IY
    if (g_strcmp0(word,"high")==0) {	
	diphone_list = g_list_append(diphone_list, "hh-aa");
	diphone_list = g_list_append(diphone_list, "aa-iy");	    
    }	
   
    //house HH_AA AA_UH UH_S
    if (g_strcmp0(word,"house")==0) {	
	diphone_list = g_list_append(diphone_list, "hh-aa");
	diphone_list = g_list_append(diphone_list, "aa-uh");
	diphone_list = g_list_append(diphone_list, "uh-s");	   
    }	
  
    //holiday HH_AA AA_L L_AH AH_D D_EH EH_IY
    if (g_strcmp0(word,"holiday")==0) {	
	diphone_list = g_list_append(diphone_list, "hh-aa");
	diphone_list = g_list_append(diphone_list, "aa-l");
	diphone_list = g_list_append(diphone_list, "l-ah");
	diphone_list = g_list_append(diphone_list, "ah-d");			
	diphone_list = g_list_append(diphone_list, "d-eh");	
	diphone_list = g_list_append(diphone_list, "eh-iy");
    }	
    
    //home HH_AO AO_UH UH_M
    if (g_strcmp0(word,"home")==0) {	
	diphone_list = g_list_append(diphone_list, "hh-ao");
	diphone_list = g_list_append(diphone_list, "ao-uh");
	diphone_list = g_list_append(diphone_list, "uh-m");
    }	
           
    //hospital HH_AA AA_S S_P P_IH IH_T T_AH AH_L
    if (g_strcmp0(word,"hospital")==0) {	
	diphone_list = g_list_append(diphone_list, "hh-aa");
	diphone_list = g_list_append(diphone_list, "aa-s");
	diphone_list = g_list_append(diphone_list, "s-p");
	diphone_list = g_list_append(diphone_list, "p-ih");			
	diphone_list = g_list_append(diphone_list, "ih-t");	
	diphone_list = g_list_append(diphone_list, "t-ah");			
	diphone_list = g_list_append(diphone_list, "ah-l");	    
    }	
       
    //------------------------------------------------------------------
    // I Words
    //------------------------------------------------------------------
    //insurance IH_N N_SH SH_UH UH_R R_AH AH_N N_S
   if (g_strcmp0(word,"insurance")==0) {	
	diphone_list = g_list_append(diphone_list, "ih-n");
	diphone_list = g_list_append(diphone_list, "n-sh");
	diphone_list = g_list_append(diphone_list, "sh-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");			
	diphone_list = g_list_append(diphone_list, "r-ah");	
	diphone_list = g_list_append(diphone_list, "ah-n");			
	diphone_list = g_list_append(diphone_list, "n-s");	    
    }	
   
    //interview IH_N N_T T_UH UH_R R_V V_Y Y_UW
    if (g_strcmp0(word,"interview")==0) {	
	diphone_list = g_list_append(diphone_list, "ih-n");
	diphone_list = g_list_append(diphone_list, "n-t");
	diphone_list = g_list_append(diphone_list, "t-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");			
	diphone_list = g_list_append(diphone_list, "r-v");	
	diphone_list = g_list_append(diphone_list, "v-y");			
	diphone_list = g_list_append(diphone_list, "y-uw");	    
    }	
   
    //investment IH_N N_V V_EH EH_S S_T T_M M_AH AH_N N_T
    if (g_strcmp0(word,"investment")==0) {	
	diphone_list = g_list_append(diphone_list, "ih-n");
	diphone_list = g_list_append(diphone_list, "n-v");
	diphone_list = g_list_append(diphone_list, "v-eh");
	diphone_list = g_list_append(diphone_list, "eh-s");			
	diphone_list = g_list_append(diphone_list, "s-t");	
	diphone_list = g_list_append(diphone_list, "t-m");			
	diphone_list = g_list_append(diphone_list, "m-ah");
	diphone_list = g_list_append(diphone_list, "ah-n");	
	diphone_list = g_list_append(diphone_list, "n-t");		    
    }	
    
    //investments IH_N N_V V_EH EH_S S_T T_M M_AH AH_N N_T T_S
    if (g_strcmp0(word,"investments")==0) {	
	diphone_list = g_list_append(diphone_list, "ih-n");
	diphone_list = g_list_append(diphone_list, "n-v");
	diphone_list = g_list_append(diphone_list, "v-eh");
	diphone_list = g_list_append(diphone_list, "eh-s");			
	diphone_list = g_list_append(diphone_list, "s-t");	
	diphone_list = g_list_append(diphone_list, "t-m");			
	diphone_list = g_list_append(diphone_list, "m-ah");
	diphone_list = g_list_append(diphone_list, "ah-n");	
	diphone_list = g_list_append(diphone_list, "n-t");
	diphone_list = g_list_append(diphone_list, "t-s");		    
    }	
   
    //invoice IH_N N_V V_AO AO_IY IY_S
    if (g_strcmp0(word,"invoice")==0) {	
	diphone_list = g_list_append(diphone_list, "ih-n");
	diphone_list = g_list_append(diphone_list, "n-v");
	diphone_list = g_list_append(diphone_list, "v-ao");
	diphone_list = g_list_append(diphone_list, "ao-iy");			
	diphone_list = g_list_append(diphone_list, "iy-s");
    }	
    
    
    //------------------------------------------------------------------
    // J Words
    //------------------------------------------------------------------
    //if (g_strcmp0(word,"")==0) {	
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	    
    //}	
    
    
    
    //journey JH_UH UH_R R_N N_IY
    if (g_strcmp0(word,"journey")==0) {	
	diphone_list = g_list_append(diphone_list, "jh-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");
	diphone_list = g_list_append(diphone_list, "r-n");
	diphone_list = g_list_append(diphone_list, "n-iy");	
    }	
    
    //------------------------------------------------------------------
    // K Words
    //------------------------------------------------------------------
    //if (g_strcmp0(word,"")==0) {	
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	    
    //}	
    //------------------------------------------------------------------
    // L Words
    //------------------------------------------------------------------
    //if (g_strcmp0(word,"")==0) {	
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	    
    //}	
    
    
    //lecture L_EH EH_K K_CH CH_UH UH_R
    if (g_strcmp0(word,"lecture")==0) {	
	diphone_list = g_list_append(diphone_list, "l-eh");
	diphone_list = g_list_append(diphone_list, "eh-k");
	diphone_list = g_list_append(diphone_list, "k-ch");
	diphone_list = g_list_append(diphone_list, "ch-uh");			
	diphone_list = g_list_append(diphone_list, "uh-r");		    
    }	
    
   
	//legal L_IY IY_G G_AH AH_L
	if (g_strcmp0(word,"legal")==0) {	
	diphone_list = g_list_append(diphone_list, "l-iy");
	diphone_list = g_list_append(diphone_list, "iy-g");
	diphone_list = g_list_append(diphone_list, "g-ah");
	diphone_list = g_list_append(diphone_list, "ah-l");	
    }	
		
	//leisure L_EH EH_ZH ZH_UH UH_R
	if (g_strcmp0(word,"leisure")==0) {	
	diphone_list = g_list_append(diphone_list, "l-eh");
	diphone_list = g_list_append(diphone_list, "eh-zh");
	diphone_list = g_list_append(diphone_list, "zh-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");	
    }
	
	
	//library L_AA AA_IY IY_B B_R R_EH EH_R R_IY	
	if (g_strcmp0(word,"library")==0) {	
	diphone_list = g_list_append(diphone_list, "l-aa");
	diphone_list = g_list_append(diphone_list, "aa-iy");
	diphone_list = g_list_append(diphone_list, "iy-b");
	diphone_list = g_list_append(diphone_list, "b-r");			
	diphone_list = g_list_append(diphone_list, "r-eh");	
	diphone_list = g_list_append(diphone_list, "eh-r");			
	diphone_list = g_list_append(diphone_list, "r-iy");	    
    }	
	
	//license L_AA AA_IY IY_S S_AH AH_N N_S	
	if (g_strcmp0(word,"license")==0) {	
	diphone_list = g_list_append(diphone_list, "l-aa");
	diphone_list = g_list_append(diphone_list, "aa-iy");
	diphone_list = g_list_append(diphone_list, "iy-s");
	diphone_list = g_list_append(diphone_list, "s-ah");			
	diphone_list = g_list_append(diphone_list, "ah-n");	
	diphone_list = g_list_append(diphone_list, "n-s");	
    }	
	
	//letter L_EH EH_T T_UH UH_R
	if (g_strcmp0(word,"letter")==0) {	
	diphone_list = g_list_append(diphone_list, "l-eh");
	diphone_list = g_list_append(diphone_list, "eh-t");
	diphone_list = g_list_append(diphone_list, "t-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");	
    }	
	
	//lift L_IH IH_F F_T
	if (g_strcmp0(word,"lift")==0) {	
	diphone_list = g_list_append(diphone_list, "l-ih");
	diphone_list = g_list_append(diphone_list, "ih-f");
	diphone_list = g_list_append(diphone_list, "f-t");		    
    }	
	
	// linux L_IH IH_N N_AH AH_K K_S (guess work)
	if (g_strcmp0(word,"linux")==0) {	
	diphone_list = g_list_append(diphone_list, "l-ih");
	diphone_list = g_list_append(diphone_list, "ih-n");
	diphone_list = g_list_append(diphone_list, "n-ah");
	diphone_list = g_list_append(diphone_list, "ah-k");
	diphone_list = g_list_append(diphone_list, "k-s");		
    }	
	
	//low L_AO AO_UH
	if (g_strcmp0(word,"low")==0) {	
	diphone_list = g_list_append(diphone_list, "l-ao");
	diphone_list = g_list_append(diphone_list, "ao-uh");
    }	
	
	//lunch L_AH AH_N N_CH
	if (g_strcmp0(word,"lunch")==0) {	
	diphone_list = g_list_append(diphone_list, "l-ah");
	diphone_list = g_list_append(diphone_list, "ah-n");
	diphone_list = g_list_append(diphone_list, "n-ch");		    
    }	
	
    //------------------------------------------------------------------
    // M Words
    //------------------------------------------------------------------
    //if (g_strcmp0(word,"")==0) {	
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	    
    //}	
    
    
    //many M_EH EH_N N_IY    
    if (g_strcmp0(word,"many")==0) {	
	diphone_list = g_list_append(diphone_list, "m-eh");
	diphone_list = g_list_append(diphone_list, "eh-n");
	diphone_list = g_list_append(diphone_list, "n-iy");	    
    }	
    
    //match M_AE AE_CH
     if (g_strcmp0(word,"match")==0) {	
	diphone_list = g_list_append(diphone_list, "m-ae");
	diphone_list = g_list_append(diphone_list, "ae-ch");
    }	
    
    //meal M_IY IY_L    
    if (g_strcmp0(word,"meal")==0) {	
	diphone_list = g_list_append(diphone_list, "m-iy");
	diphone_list = g_list_append(diphone_list, "iy-l");	    
    }	
    
    //medical M_EH EH_D D_AH AH_K K_AH AH_L
    if (g_strcmp0(word,"medical")==0) {	
	diphone_list = g_list_append(diphone_list, "m-eh");
	diphone_list = g_list_append(diphone_list, "eh-d");
	diphone_list = g_list_append(diphone_list, "d-ah");
	diphone_list = g_list_append(diphone_list, "ah-k");			
	diphone_list = g_list_append(diphone_list, "k-ah");	
	diphone_list = g_list_append(diphone_list, "ah-l");	
    }	
    
    //meeting M_IY IY_T T_IH IH_NG
    if (g_strcmp0(word,"meeting")==0) {	
	diphone_list = g_list_append(diphone_list, "m-iy");
	diphone_list = g_list_append(diphone_list, "iy-t");
	diphone_list = g_list_append(diphone_list, "t-ih");
	diphone_list = g_list_append(diphone_list, "ih-ng");
    }	
    
    //meetings M_IY IY_T T_IH IH_NG NG_Z
     if (g_strcmp0(word,"meetings")==0) {	
	diphone_list = g_list_append(diphone_list, "m-iy");
	diphone_list = g_list_append(diphone_list, "iy-t");
	diphone_list = g_list_append(diphone_list, "t-ih");
	diphone_list = g_list_append(diphone_list, "ih-ng");
	diphone_list = g_list_append(diphone_list, "ng-z");
    }	   
    
    //meet M_IY IY_T
    if (g_strcmp0(word,"meet")==0) {	
	diphone_list = g_list_append(diphone_list, "m-iy");
	diphone_list = g_list_append(diphone_list, "iy-t");	    
    }	
    
    
    //memo M_EH EH_M M_UH
     if (g_strcmp0(word,"memo")==0) {	
	diphone_list = g_list_append(diphone_list, "m-eh");
	diphone_list = g_list_append(diphone_list, "eh-m");
	diphone_list = g_list_append(diphone_list, "m-uh");	    
    }	
    
    //memorandum M_EH EH_M M_UH UH_R R_AE AE_N N_D D_AH AH_M
    if (g_strcmp0(word,"memorandum")==0) {	
	diphone_list = g_list_append(diphone_list, "m-eh");
	diphone_list = g_list_append(diphone_list, "eh-m");
	diphone_list = g_list_append(diphone_list, "m-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");			
	diphone_list = g_list_append(diphone_list, "r-ae");	
	diphone_list = g_list_append(diphone_list, "ae-n");			
	diphone_list = g_list_append(diphone_list, "n-d");	
	diphone_list = g_list_append(diphone_list, "d-ah");
	diphone_list = g_list_append(diphone_list, "ah-m");    
    }	
    
    
    //milkman M_IH IH_L L_K K_M M_AE AE_N
    if (g_strcmp0(word,"milkman")==0) {	
	diphone_list = g_list_append(diphone_list, "m-ih");
	diphone_list = g_list_append(diphone_list, "ih-l");
	diphone_list = g_list_append(diphone_list, "l-k");
	diphone_list = g_list_append(diphone_list, "k-m");			
	diphone_list = g_list_append(diphone_list, "m-ae");	
	diphone_list = g_list_append(diphone_list, "ae-n");	
    }	
    
    //mother M_AH AH_DH DH_UH UH_R    
    if (g_strcmp0(word,"mother")==0) {	
	diphone_list = g_list_append(diphone_list, "m_ah");
	diphone_list = g_list_append(diphone_list, "ah_dh");
	diphone_list = g_list_append(diphone_list, "dh-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");	
    }	
    
    //mothers M_AH AH_DH DH_UH UH_R R_Z
    if (g_strcmp0(word,"mothers")==0) {	
	diphone_list = g_list_append(diphone_list, "m-ah");
	diphone_list = g_list_append(diphone_list, "ah-dh");
	diphone_list = g_list_append(diphone_list, "dh-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");			
	diphone_list = g_list_append(diphone_list, "r-z");
    }	
    
    //move M_UW UW_V    
    if (g_strcmp0(word,"move")==0) {	
	diphone_list = g_list_append(diphone_list, "m-uw");
	diphone_list = g_list_append(diphone_list, "uw-v");		    
    }	
    
    //movie M_UW UW_V V_IY
    if (g_strcmp0(word,"movie")==0) {	
	diphone_list = g_list_append(diphone_list, "m-uw");
	diphone_list = g_list_append(diphone_list, "uw-v");
	diphone_list = g_list_append(diphone_list, "v-iy");		    
    }	
    
    //music M_Y Y_UW UW_Z Z_IH IH_K
    if (g_strcmp0(word,"music")==0) {	
	diphone_list = g_list_append(diphone_list, "m-y");
	diphone_list = g_list_append(diphone_list, "y-uw");
	diphone_list = g_list_append(diphone_list, "uw-z");
	diphone_list = g_list_append(diphone_list, "z-ih");			
	diphone_list = g_list_append(diphone_list, "ih-k");	    
    }	
    
    //------------------------------------------------------------------
    // N Words
    //------------------------------------------------------------------
    //if (g_strcmp0(word,"")==0) {	
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	    
    //}	
    
    
    //no N_AO AO_UH
      if (g_strcmp0(word,"no")==0) {	
	diphone_list = g_list_append(diphone_list, "n-ao");
	diphone_list = g_list_append(diphone_list, "ao-uh");	    
    }	
    
    //net N_EH EH_T
    //flick F_L L_IH IH_K  
    if (g_strcmp0(word,"netflix")==0) {	
	diphone_list = g_list_append(diphone_list, "n-eh");
	diphone_list = g_list_append(diphone_list, "eh-t");
	diphone_list = g_list_append(diphone_list, "f-l");
	diphone_list = g_list_append(diphone_list, "l-ih");			
	diphone_list = g_list_append(diphone_list, "ih-k");
    }	
       
    //------------------------------------------------------------------
    // O Words
    //------------------------------------------------------------------
    //on AA_N
    //line L_AA AA_IY IY_N    
    if (g_strcmp0(word,"online")==0) {	
	diphone_list = g_list_append(diphone_list, "aa-h");
	diphone_list = g_list_append(diphone_list, "n-pau");
	diphone_list = g_list_append(diphone_list, "pau-l");
	diphone_list = g_list_append(diphone_list, "l-aa");			
	diphone_list = g_list_append(diphone_list, "aa-iy");	
	diphone_list = g_list_append(diphone_list, "iy-n");	
    }	
    
    //occurrence AH_K K_UH UH_R R_AH AH_N N_S
    if (g_strcmp0(word,"occurrence")==0) {	
	diphone_list = g_list_append(diphone_list, "ah-k");
	diphone_list = g_list_append(diphone_list, "k-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");
	diphone_list = g_list_append(diphone_list, "r-ah");			
	diphone_list = g_list_append(diphone_list, "ah-n");	
	diphone_list = g_list_append(diphone_list, "n-s");
    }	
    
    //operation AA_P P_UH UH_R R_EH EH_IY IY_SH SH_AH AH_N
    if (g_strcmp0(word,"operation")==0) {	
	diphone_list = g_list_append(diphone_list, "aa-p");
	diphone_list = g_list_append(diphone_list, "p-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");
	diphone_list = g_list_append(diphone_list, "r-eh");			
	diphone_list = g_list_append(diphone_list, "eh-iy");	
	diphone_list = g_list_append(diphone_list, "iy-sh");			
	diphone_list = g_list_append(diphone_list, "sh-ah");
	diphone_list = g_list_append(diphone_list, "ah-n");	    
    }	
    
    //------------------------------------------------------------------
    // P Words
    //------------------------------------------------------------------
   //if (g_strcmp0(word,"")==0) {	
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	    
    //}	
   
   
    if (g_strcmp0(word,"pau")==0) {	
	diphone_list = g_list_append(diphone_list, "pau-pau");		    
    }	
    if (g_strcmp0(word,"paupau")==0) {	
	diphone_list = g_list_append(diphone_list, "pau-pau");
	diphone_list = g_list_append(diphone_list, "pau-pau");		    
    }
    
    //point P_AO AO_IY IY_N N_T
     if (g_strcmp0(word,"point")==0) {	
	diphone_list = g_list_append(diphone_list, "p-ao");
	diphone_list = g_list_append(diphone_list, "ao-iy");
	diphone_list = g_list_append(diphone_list, "iy-n");
	diphone_list = g_list_append(diphone_list, "n-t");		    
    }
    
    //parcel P_AA AA_R R_S S_AH AH_L
    if (g_strcmp0(word,"parcel")==0) {	
	diphone_list = g_list_append(diphone_list, "p-aa");
	diphone_list = g_list_append(diphone_list, "aa-r");
	diphone_list = g_list_append(diphone_list, "r-s");
	diphone_list = g_list_append(diphone_list, "s-ah");			
	diphone_list = g_list_append(diphone_list, "ah-l");	
	 }	
    
    //party P_AA AA_R R_T T_IY
    if (g_strcmp0(word,"party")==0) {	
	diphone_list = g_list_append(diphone_list, "p-aa");
	diphone_list = g_list_append(diphone_list, "aa-r");
	diphone_list = g_list_append(diphone_list, "r-t");
	diphone_list = g_list_append(diphone_list, "t-iy");	
    }	
    
    //pay P_EH EH_IY
    if (g_strcmp0(word,"pay")==0) {	
	diphone_list = g_list_append(diphone_list, "p-eh");
	diphone_list = g_list_append(diphone_list, "eh-iy");
    }
    	
    //payment P_EH EH_IY IY_M M_AH AH_N N_T
    if (g_strcmp0(word,"payment")==0) {	
	diphone_list = g_list_append(diphone_list, "p-eh");
	diphone_list = g_list_append(diphone_list, "eh-iy");
	diphone_list = g_list_append(diphone_list, "iy-m");
	diphone_list = g_list_append(diphone_list, "m-ah");			
	diphone_list = g_list_append(diphone_list, "ah-n");	
	diphone_list = g_list_append(diphone_list, "n-t");
    }	
    
    //pension P_EH EH_N N_SH SH_AH AH_N
    if (g_strcmp0(word,"pension")==0) {	
	diphone_list = g_list_append(diphone_list, "p-eh");
	diphone_list = g_list_append(diphone_list, "eh-n");
	diphone_list = g_list_append(diphone_list, "n-sh");
	diphone_list = g_list_append(diphone_list, "sh-ah");			
	diphone_list = g_list_append(diphone_list, "ah-n");	
    }	
    
    //personal P_UH UH_R R_S S_IH IH_N N_IH IH_L
    if (g_strcmp0(word,"personal")==0) {	
	diphone_list = g_list_append(diphone_list, "p-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");
	diphone_list = g_list_append(diphone_list, "r-s");
	diphone_list = g_list_append(diphone_list, "s-ih");			
	diphone_list = g_list_append(diphone_list, "ih-n");	
	diphone_list = g_list_append(diphone_list, "n-ih");			
	diphone_list = g_list_append(diphone_list, "ih-l");	    
    }	
    
    //phone F_AO AO_UH UH_N
    if (g_strcmp0(word,"phone")==0) {	
	diphone_list = g_list_append(diphone_list, "f-ao");
	diphone_list = g_list_append(diphone_list, "ao-uh");
	diphone_list = g_list_append(diphone_list, "uh-n");
    }	
    
    //picnic P_IH IH_K K_N N_IH IH_K
     if (g_strcmp0(word,"picnic")==0) {	
	diphone_list = g_list_append(diphone_list, "p-ih");
	diphone_list = g_list_append(diphone_list, "ih-k");
	diphone_list = g_list_append(diphone_list, "k-n");
	diphone_list = g_list_append(diphone_list, "n-ih");			
	diphone_list = g_list_append(diphone_list, "ih-k");	
    }	
    
    //police P_AH AH_L L_IY IY_S
    if (g_strcmp0(word,"police")==0) {	
	diphone_list = g_list_append(diphone_list, "p-ah");
	diphone_list = g_list_append(diphone_list, "ah-l");
	diphone_list = g_list_append(diphone_list, "l-iy");
	diphone_list = g_list_append(diphone_list, "iy-s");	
    }	
    
    //post P_AO AO_UH UH_S S_T
    if (g_strcmp0(word,"post")==0) {	
	diphone_list = g_list_append(diphone_list, "p-ao");
	diphone_list = g_list_append(diphone_list, "ao-uh");
	diphone_list = g_list_append(diphone_list, "uh-s");
	diphone_list = g_list_append(diphone_list, "s-t");
    }	
    
    //priority P_R R_AA AA_IY IY_AO AO_R R_AH AH_T T_IY
    if (g_strcmp0(word,"priority")==0) {	
	diphone_list = g_list_append(diphone_list, "p-r");
	diphone_list = g_list_append(diphone_list, "r-aa");
	diphone_list = g_list_append(diphone_list, "aa-iy");
	diphone_list = g_list_append(diphone_list, "iy-ao");			
	diphone_list = g_list_append(diphone_list, "ao-r");	
	diphone_list = g_list_append(diphone_list, "r-ah");			
	diphone_list = g_list_append(diphone_list, "ah-t");	
	diphone_list = g_list_append(diphone_list, "t-iy");	    
    }	
   
    //project P_R R_AA AA_JH JH_EH EH_K K_T
    if (g_strcmp0(word,"project")==0) {	
	diphone_list = g_list_append(diphone_list, "p-r");
	diphone_list = g_list_append(diphone_list, "r-aa");
	diphone_list = g_list_append(diphone_list, "aa-jh");
	diphone_list = g_list_append(diphone_list, "jh-eh");			
	diphone_list = g_list_append(diphone_list, "eh-k");	
	diphone_list = g_list_append(diphone_list, "k-t");	
    }	
    
    
    //planning P_L L_AE AE_N N_IH IH_NG
    if (g_strcmp0(word,"planning")==0) {	
	diphone_list = g_list_append(diphone_list, "p-l");
	diphone_list = g_list_append(diphone_list, "l-ae");
	diphone_list = g_list_append(diphone_list, "ae-n");
	diphone_list = g_list_append(diphone_list, "n-ih");			
	diphone_list = g_list_append(diphone_list, "ih-ng");
	    
    }	
	
	//plan P_L L_AE AE_N
	if (g_strcmp0(word,"plan")==0) {	
	diphone_list = g_list_append(diphone_list, "p-l");
	diphone_list = g_list_append(diphone_list, "l-ae");
	diphone_list = g_list_append(diphone_list, "ae-n");	    
    }	
	
	
	//plans P_L L_AE AE_N N_Z
	//plant P_L L_AE AE_N N_T
	if (g_strcmp0(word,"plant")==0) {	
	diphone_list = g_list_append(diphone_list, "p-l");
	diphone_list = g_list_append(diphone_list, "l-ae");
	diphone_list = g_list_append(diphone_list, "ae-n");
	diphone_list = g_list_append(diphone_list, "n-t");	
    }	
    
    //------------------------------------------------------------------
    // Q Words
    //------------------------------------------------------------------
    //quiz K_W W_IH IH_Z
    if (g_strcmp0(word,"quiz")==0) {	
	diphone_list = g_list_append(diphone_list, "k-w");
	diphone_list = g_list_append(diphone_list, "w-ih");
	diphone_list = g_list_append(diphone_list, "ih-z");
    }	
    
    
    //------------------------------------------------------------------
    // R Words
    //------------------------------------------------------------------
    //if (g_strcmp0(word,"")==0) {	
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	    
    //}	
    
    //radio R_EH EH_IY IY_D D_IY IY_AO AO_UH
    if (g_strcmp0(word,"radio")==0) {	
	diphone_list = g_list_append(diphone_list, "r-eh");
	diphone_list = g_list_append(diphone_list, "eh-iy");
	diphone_list = g_list_append(diphone_list, "iy-d");
	diphone_list = g_list_append(diphone_list, "d-iy");			
	diphone_list = g_list_append(diphone_list, "iy-ao");	
	diphone_list = g_list_append(diphone_list, "ao-uh");
    }	
    
    //red R_EH EH_D as in red alert
    if (g_strcmp0(word,"red")==0) {	
	diphone_list = g_list_append(diphone_list, "r-eh");
	diphone_list = g_list_append(diphone_list, "eh-d");
	}	
    
    // remember R_IH IH_M M_EH EH_M M_B B_UH UH_R
    if (g_strcmp0(word,"remember")==0) {	
	diphone_list = g_list_append(diphone_list, "r-ih");
	diphone_list = g_list_append(diphone_list, "ih-m");
	diphone_list = g_list_append(diphone_list, "m-eh");
	diphone_list = g_list_append(diphone_list, "eh-m");			
	diphone_list = g_list_append(diphone_list, "m-b");	
	diphone_list = g_list_append(diphone_list, "b-uh");			
	diphone_list = g_list_append(diphone_list, "uh-r");	    
    }	
    
    //remembrance R_IY IY_M M_EH EH_M M_B B_R R_AH AH_N N_S
     if (g_strcmp0(word,"remembrance")==0) {	
	diphone_list = g_list_append(diphone_list, "r-iy");
	diphone_list = g_list_append(diphone_list, "iy-m");
	diphone_list = g_list_append(diphone_list, "m-eh");
	diphone_list = g_list_append(diphone_list, "eh-m");			
	diphone_list = g_list_append(diphone_list, "m-b");	
	diphone_list = g_list_append(diphone_list, "b-r");			
	diphone_list = g_list_append(diphone_list, "r-ah");
	diphone_list = g_list_append(diphone_list, "ah-n");	
	diphone_list = g_list_append(diphone_list, "n-s");	    
    }	
        
    //reminder R_IY IY_M M_AA AA_IY IY_N N_D D_UH UH_R
    if (g_strcmp0(word,"reminder")==0) {	
	diphone_list = g_list_append(diphone_list, "r-iy");
	diphone_list = g_list_append(diphone_list, "iy-m");
	diphone_list = g_list_append(diphone_list, "m-aa");
	diphone_list = g_list_append(diphone_list, "aa-iy");			
	diphone_list = g_list_append(diphone_list, "iy-n");	
	diphone_list = g_list_append(diphone_list, "n-d");			
	diphone_list = g_list_append(diphone_list, "d-uh");	
	diphone_list = g_list_append(diphone_list, "uh-r");    
    }	
        
    //repair R_IH IH_P P_EH EH_R
    if (g_strcmp0(word,"repair")==0) {	
	diphone_list = g_list_append(diphone_list, "r-ih");
	diphone_list = g_list_append(diphone_list, "ih-p");
	diphone_list = g_list_append(diphone_list, "p-eh");
	diphone_list = g_list_append(diphone_list, "eh-r");	
    }	
    
    //restaurant R_EH EH_S S_T T_UH UH_R R_AA AA_N N_T
    if (g_strcmp0(word,"restaurant")==0) {	
	diphone_list = g_list_append(diphone_list, "r-eh");
	diphone_list = g_list_append(diphone_list, "eh-s");
	diphone_list = g_list_append(diphone_list, "s-t");
	diphone_list = g_list_append(diphone_list, "t-uh");			
	diphone_list = g_list_append(diphone_list, "uh-r");	
	diphone_list = g_list_append(diphone_list, "r-aa");			
	diphone_list = g_list_append(diphone_list, "aa-n");
	diphone_list = g_list_append(diphone_list, "n-t");		    
    }	
    
    //------------------------------------------------------------------
    // S Words
    //------------------------------------------------------------------
    //if (g_strcmp0(word,"")==0) {	
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	    
    //}	
    
    
    //shop SH_AA AA_P
    if (g_strcmp0(word,"shop")==0) {	
	diphone_list = g_list_append(diphone_list, "sh-aa");
	diphone_list = g_list_append(diphone_list, "aa-p");		    
    }	
    
    
    //shares SH_EH EH_R R_Z
    if (g_strcmp0(word,"shares")==0) {	
	diphone_list = g_list_append(diphone_list, "s-eh");
	diphone_list = g_list_append(diphone_list, "eh-r");
	diphone_list = g_list_append(diphone_list, "r-z");	   
    }	
    
    //shopping SH_AA AA_P P_IH IH_NG
    if (g_strcmp0(word,"shopping")==0) {	
	diphone_list = g_list_append(diphone_list, "sh-aa");
	diphone_list = g_list_append(diphone_list, "aa-p");
	diphone_list = g_list_append(diphone_list, "p-ih");
	diphone_list = g_list_append(diphone_list, "ih-ng");
    }	
    
    //seed S_IY IY_D
    if (g_strcmp0(word,"seed")==0) {	
	diphone_list = g_list_append(diphone_list, "s-iy");
	diphone_list = g_list_append(diphone_list, "iy-d");		   
    }	
    
    //seeds S_IY IY_D D_Z
    if (g_strcmp0(word,"seeds")==0) {	
	diphone_list = g_list_append(diphone_list, "s-iy");
	diphone_list = g_list_append(diphone_list, "iy-d");
	diphone_list = g_list_append(diphone_list, "d-z");	   
    }	
    
    //service S_UH UH_R R_V V_AH AH_S
    if (g_strcmp0(word,"service")==0) {	
	diphone_list = g_list_append(diphone_list, "s-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");
	diphone_list = g_list_append(diphone_list, "r-v");
	diphone_list = g_list_append(diphone_list, "v-ah");			
	diphone_list = g_list_append(diphone_list, "ah-s");			    
    }	
    
    //shares SH_EH EH_R R_Z
    if (g_strcmp0(word,"shares")==0) {	
	diphone_list = g_list_append(diphone_list, "sh-eh");
	diphone_list = g_list_append(diphone_list, "eh-r");
	diphone_list = g_list_append(diphone_list, "r-z");
    }	
    
    //show SH_AO AO_UH
    if (g_strcmp0(word,"show")==0) {	
	diphone_list = g_list_append(diphone_list, "sh-ao");
	diphone_list = g_list_append(diphone_list, "ao-uh");    
    }
    
    	
    //solicitor S_AH AH_L L_IH IH_S S_AH AH_T T_UH UH_R
    if (g_strcmp0(word,"solicitor")==0) {	
	diphone_list = g_list_append(diphone_list, "s-ah");
	diphone_list = g_list_append(diphone_list, "ah-l");
	diphone_list = g_list_append(diphone_list, "l-ih");
	diphone_list = g_list_append(diphone_list, "ih-s");			
	diphone_list = g_list_append(diphone_list, "s-ah");	
	diphone_list = g_list_append(diphone_list, "ah-t");			
	diphone_list = g_list_append(diphone_list, "t-uh");	
	diphone_list = g_list_append(diphone_list, "uh-r");    
    }	
    
    //sow S_AA AA_UH
    if (g_strcmp0(word,"sow")==0) {	
	diphone_list = g_list_append(diphone_list, "s-ao");
	diphone_list = g_list_append(diphone_list, "ao-uh");
     }
    
    //sowing S_AO AO_UH UH_IH IH_NG
    if (g_strcmp0(word,"sowing")==0) {	
	diphone_list = g_list_append(diphone_list, "s-ao");
	diphone_list = g_list_append(diphone_list, "ao-uh");
	diphone_list = g_list_append(diphone_list, "uh-ih");
	diphone_list = g_list_append(diphone_list, "ih-ng");
    }	
    
    //special S_P P_EH EH_SH SH_AH AH_L
    if (g_strcmp0(word,"special")==0) {	
	diphone_list = g_list_append(diphone_list, "s-p");
	diphone_list = g_list_append(diphone_list, "p-eh");
	diphone_list = g_list_append(diphone_list, "eh-sh");
	diphone_list = g_list_append(diphone_list, "sh-ah");			
	diphone_list = g_list_append(diphone_list, "ah-l");
    }	
   
    //sport S_P P_AO AO_R R_T
     if (g_strcmp0(word,"sport")==0) {	
	diphone_list = g_list_append(diphone_list, "s-p");
	diphone_list = g_list_append(diphone_list, "p-ao");
	diphone_list = g_list_append(diphone_list, "ao-r");
	diphone_list = g_list_append(diphone_list, "r-t");
    }	
    
    
    //station S_T T_EH EH_IY IY_SH SH_AH AH_N
    if (g_strcmp0(word,"station")==0) {	
	diphone_list = g_list_append(diphone_list, "s-t");
	diphone_list = g_list_append(diphone_list, "t-eh");
	diphone_list = g_list_append(diphone_list, "eh-iy");
	diphone_list = g_list_append(diphone_list, "iy-sh");			
	diphone_list = g_list_append(diphone_list, "sh-ah");	
	diphone_list = g_list_append(diphone_list, "ah-n");	
    }	
   
    //stocks S_T T_AA AA_K K_S
    if (g_strcmp0(word,"stocks")==0) {	
	diphone_list = g_list_append(diphone_list, "s-t");
	diphone_list = g_list_append(diphone_list, "t-aa");
	diphone_list = g_list_append(diphone_list, "aa-k");
	diphone_list = g_list_append(diphone_list, "k-s");
    }	
    
    //super S_UW UW_P P_UH UH_R
    //market M_AA AA_R R_K K_AH AH_T
    if (g_strcmp0(word,"supermarket")==0) {	
	diphone_list = g_list_append(diphone_list, "s-uw");
	diphone_list = g_list_append(diphone_list, "uw-p");
	diphone_list = g_list_append(diphone_list, "p-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");
	diphone_list = g_list_append(diphone_list, "r-pau");
	diphone_list = g_list_append(diphone_list, "pau-m");			
	diphone_list = g_list_append(diphone_list, "m-aa");	
	diphone_list = g_list_append(diphone_list, "aa-r");			
	diphone_list = g_list_append(diphone_list, "r-k");
	diphone_list = g_list_append(diphone_list, "k-ah");			
	diphone_list = g_list_append(diphone_list, "ah-t");	   	    
    }	
    
    
    
    //subscription S_AH AH_B B_S S_K K_R R_IH IH_P P_SH SH_AH AH_N
    if (g_strcmp0(word,"subscription")==0) {	
	diphone_list = g_list_append(diphone_list, "s-ah");
	diphone_list = g_list_append(diphone_list, "ah-b");
	diphone_list = g_list_append(diphone_list, "b-s");
	diphone_list = g_list_append(diphone_list, "s-k");			
	diphone_list = g_list_append(diphone_list, "k-r");	
	diphone_list = g_list_append(diphone_list, "r-ih");			
	diphone_list = g_list_append(diphone_list, "ih-p");
	diphone_list = g_list_append(diphone_list, "p-sh");	
	diphone_list = g_list_append(diphone_list, "sh-ah");	
	diphone_list = g_list_append(diphone_list, "ah-n");		    
    }	
    
    
    //system S_IH IH_S S_T T_AH AH_M
    if (g_strcmp0(word,"system")==0) {	
	diphone_list = g_list_append(diphone_list, "s-ih");
	diphone_list = g_list_append(diphone_list, "ih-s");
	diphone_list = g_list_append(diphone_list, "s-t");
	diphone_list = g_list_append(diphone_list, "t-ah");			
	diphone_list = g_list_append(diphone_list, "ah-m");
    }	
    
    //sister S_IH IH_S S_T T_UH UH_R
    if (g_strcmp0(word,"sister")==0) {	
	diphone_list = g_list_append(diphone_list, "s-ih");
	diphone_list = g_list_append(diphone_list, "ih-s");
	diphone_list = g_list_append(diphone_list, "s-t");
	diphone_list = g_list_append(diphone_list, "t-uh");			
	diphone_list = g_list_append(diphone_list, "uh-r");	
    }	
   
    //------------------------------------------------------------------
    // T Words
    //------------------------------------------------------------------
    
    //talk T_AO AO_K
    if (g_strcmp0(word,"talk")==0) {	
	diphone_list = g_list_append(diphone_list, "t-ao");
	diphone_list = g_list_append(diphone_list, "ao-k");		    
    }	
    
    //today T_AH AH_D D_EH EH_IY
    if (g_strcmp0(word,"today")==0) {	
	diphone_list = g_list_append(diphone_list, "t-ah");
	diphone_list = g_list_append(diphone_list, "ah-d");
	diphone_list = g_list_append(diphone_list, "d-eh");
	diphone_list = g_list_append(diphone_list, "eh-iy");
    }	
    
    //tax T_AE AE_K K_S
    if (g_strcmp0(word,"tax")==0) {	
	diphone_list = g_list_append(diphone_list, "t-ae");
	diphone_list = g_list_append(diphone_list, "ae-k");
	diphone_list = g_list_append(diphone_list, "k-s");
    }	
    
    //theatre TH_IY IY_AH AH_T T_UH UH_R
    if (g_strcmp0(word,"theatre")==0) {	
	diphone_list = g_list_append(diphone_list, "th-iy");
	diphone_list = g_list_append(diphone_list, "iy-ah");
	diphone_list = g_list_append(diphone_list, "ah-t");
	diphone_list = g_list_append(diphone_list, "t-uh");			
	diphone_list = g_list_append(diphone_list, "uh-r");	
    }	
    
    //to T_UW
    if (g_strcmp0(word,"to")==0) {	
	diphone_list = g_list_append(diphone_list, "t-uw");
    }	
    
    //train T_R R_EH EH_IY IY_N
    if (g_strcmp0(word,"train")==0) {	
	diphone_list = g_list_append(diphone_list, "t-r");
	diphone_list = g_list_append(diphone_list, "r-eh");
	diphone_list = g_list_append(diphone_list, "eh-iy");
	diphone_list = g_list_append(diphone_list, "iy-n");	
    }	
    
    //tea T_IY
    if (g_strcmp0(word,"tea")==0) {	
	diphone_list = g_list_append(diphone_list, "t-iy");
    }	
    
    //tearoom T_R R_UH UH_R R_UW UW_M
    if (g_strcmp0(word,"tearoom")==0) {	
	diphone_list = g_list_append(diphone_list, "t-r");
	diphone_list = g_list_append(diphone_list, "r-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");
	diphone_list = g_list_append(diphone_list, "r-uw");			
	diphone_list = g_list_append(diphone_list, "uw-m");	
	 }	
    
    //training T_R R_EH EH_IY IY_N N_IH IH_NG
    if (g_strcmp0(word,"training")==0) {	
	diphone_list = g_list_append(diphone_list, "t-r");
	diphone_list = g_list_append(diphone_list, "r-eh");
	diphone_list = g_list_append(diphone_list, "eh-iy");
	diphone_list = g_list_append(diphone_list, "iy-n");			
	diphone_list = g_list_append(diphone_list, "n-ih");	
	diphone_list = g_list_append(diphone_list, "ih-ng");
    }	
    
    //travel T_R R_AE AE_V V_AH AH_L
    if (g_strcmp0(word,"travel")==0) {	
	diphone_list = g_list_append(diphone_list, "t-r");
	diphone_list = g_list_append(diphone_list, "r-ae");
	diphone_list = g_list_append(diphone_list, "ae-v");
	diphone_list = g_list_append(diphone_list, "v-ah");			
	diphone_list = g_list_append(diphone_list, "ah-l");	
    }	
    
    //television T_EH EH_L L_AH AH_V V_IH IH_ZH ZH_AH AH_N
    if (g_strcmp0(word,"television")==0) {	
	diphone_list = g_list_append(diphone_list, "t-eh");
	diphone_list = g_list_append(diphone_list, "eh-l");
	diphone_list = g_list_append(diphone_list, "l-ah");
	diphone_list = g_list_append(diphone_list, "ah-v");			
	diphone_list = g_list_append(diphone_list, "v-ih");	
	diphone_list = g_list_append(diphone_list, "ih-zh");			
	diphone_list = g_list_append(diphone_list, "zh-ah");
	diphone_list = g_list_append(diphone_list, "ah-n");	    
    }	
    
    //------------------------------------------------------------------
    // U Words
    //------------------------------------------------------------------
    //unknown AH_N N_N N_AO AO_UH UH_N
    if (g_strcmp0(word,"unknown")==0) {	
	diphone_list = g_list_append(diphone_list, "ah-n");
	diphone_list = g_list_append(diphone_list, "n-n");
	diphone_list = g_list_append(diphone_list, "n-ao");
	diphone_list = g_list_append(diphone_list, "ao-uh");
	diphone_list = g_list_append(diphone_list, "uh-n");
    }	
    
    
    //urgent UH_R R_JH JH_AH AH_N N_T
     if (g_strcmp0(word,"urgent")==0) {	
	diphone_list = g_list_append(diphone_list, "uh-r");
	diphone_list = g_list_append(diphone_list, "r-jh");
	diphone_list = g_list_append(diphone_list, "jh-ah");
	diphone_list = g_list_append(diphone_list, "ah-n");			
	diphone_list = g_list_append(diphone_list, "n-t");	
    }	
    
    //------------------------------------------------------------------
    // V Words
    //------------------------------------------------------------------
    //version V_UH UH_R R_ZH ZH_AH AH_N
    if (g_strcmp0(word,"version")==0) {	
	diphone_list = g_list_append(diphone_list, "v-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");
	diphone_list = g_list_append(diphone_list, "r-zh");
	diphone_list = g_list_append(diphone_list, "zh-ah");
	diphone_list = g_list_append(diphone_list, "ah-n");
    }	
    
    //vacation V_EH EH_IY IY_K K_EH EH_IY IY_SH SH_AH AH_N
    if (g_strcmp0(word,"vacation")==0) {	
	diphone_list = g_list_append(diphone_list, "v-eh");
	diphone_list = g_list_append(diphone_list, "eh-iy");
	diphone_list = g_list_append(diphone_list, "iy-k");
	diphone_list = g_list_append(diphone_list, "k-eh");			
	diphone_list = g_list_append(diphone_list, "eh-iy");	
	diphone_list = g_list_append(diphone_list, "iy-sh");			
	diphone_list = g_list_append(diphone_list, "sh-ah");
	diphone_list = g_list_append(diphone_list, "ah-n");	    
    }	
    
    //vaccination V_AE AE_K K_S S_AH AH_N N_EH EH_IY IY_SH SH_AH AH_N    
    if (g_strcmp0(word,"vaccination")==0) {	
	diphone_list = g_list_append(diphone_list, "v-ae");
	diphone_list = g_list_append(diphone_list, "ae-k");
	diphone_list = g_list_append(diphone_list, "k-s");
	diphone_list = g_list_append(diphone_list, "s-ah");			
	diphone_list = g_list_append(diphone_list, "ah-n");	
	diphone_list = g_list_append(diphone_list, "n-eh");			
	diphone_list = g_list_append(diphone_list, "eh-iy");
	diphone_list = g_list_append(diphone_list, "iy-sh");
	diphone_list = g_list_append(diphone_list, "sh-ah");
	diphone_list = g_list_append(diphone_list, "ah-n");	    
    }	
    
    //valentine V_AE AE_L L_AH AH_N N_T T_AA AA_IY IY_N
    if (g_strcmp0(word,"valentine")==0) {	
	diphone_list = g_list_append(diphone_list, "v-ae");
	diphone_list = g_list_append(diphone_list, "ae-l");
	diphone_list = g_list_append(diphone_list, "l-ah");
	diphone_list = g_list_append(diphone_list, "ah-n");			
	diphone_list = g_list_append(diphone_list, "n-t");	
	diphone_list = g_list_append(diphone_list, "t-aa");			
	diphone_list = g_list_append(diphone_list, "aa-iy");	
	diphone_list = g_list_append(diphone_list, "iy-n");	    
    }	
       
    //valentines V_AE AE_L L_AH AH_N N_T T_AA AA_IY IY_N N_Z
    if (g_strcmp0(word,"valentines")==0) {	
	diphone_list = g_list_append(diphone_list, "v-ae");
	diphone_list = g_list_append(diphone_list, "ae-l");
	diphone_list = g_list_append(diphone_list, "l-ah");
	diphone_list = g_list_append(diphone_list, "ah-n");			
	diphone_list = g_list_append(diphone_list, "n-t");	
	diphone_list = g_list_append(diphone_list, "t-aa");			
	diphone_list = g_list_append(diphone_list, "aa-iy");	
	diphone_list = g_list_append(diphone_list, "iy-n");
	diphone_list = g_list_append(diphone_list, "n-z");		    
    }	
       
    //vehicle V_IY IY_HH HH_IH IH_K K_AH AH_L
     if (g_strcmp0(word,"vehicle")==0) {	
	diphone_list = g_list_append(diphone_list, "v-iy");
	diphone_list = g_list_append(diphone_list, "iy-hh");
	diphone_list = g_list_append(diphone_list, "hh-ih");
	diphone_list = g_list_append(diphone_list, "ih-k");			
	diphone_list = g_list_append(diphone_list, "k-ah");	
	diphone_list = g_list_append(diphone_list, "ah-l");	
    }	
    
    //virus V_AA AA_IY IY_R R_AH AH_S
    if (g_strcmp0(word,"virus")==0) {	
	diphone_list = g_list_append(diphone_list, "v-aa");
	diphone_list = g_list_append(diphone_list, "aa-iy");
	diphone_list = g_list_append(diphone_list, "iy-r");
	diphone_list = g_list_append(diphone_list, "r-ah");			
	diphone_list = g_list_append(diphone_list, "ah-s");	
    }	
     
    //visa V_IY IY_Z Z_AH
    if (g_strcmp0(word,"visa")==0) {	
	diphone_list = g_list_append(diphone_list, "v-iy");
	diphone_list = g_list_append(diphone_list, "iy-z");
	diphone_list = g_list_append(diphone_list, "z-ah");
    }	
    
    //visit V_IH IH_Z Z_AH AH_T
    if (g_strcmp0(word,"visit")==0) {	
	diphone_list = g_list_append(diphone_list, "v-ih");
	diphone_list = g_list_append(diphone_list, "ih-z");
	diphone_list = g_list_append(diphone_list, "z-ah");
	diphone_list = g_list_append(diphone_list, "ah-t");
    }	
    
    //visitor V_IH IH_Z Z_AH AH_T T_UH UH_R
    if (g_strcmp0(word,"visitor")==0) {	
	diphone_list = g_list_append(diphone_list, "v-ih");
	diphone_list = g_list_append(diphone_list, "ih-z");
	diphone_list = g_list_append(diphone_list, "z-ah");
	diphone_list = g_list_append(diphone_list, "ah-t");
	diphone_list = g_list_append(diphone_list, "t-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");
    }	
   
    //visitors V_IH IH_Z Z_AH AH_T T_UH UH_R R_Z
    if (g_strcmp0(word,"visitors")==0) {	
	diphone_list = g_list_append(diphone_list, "v-ih");
	diphone_list = g_list_append(diphone_list, "ih-z");
	diphone_list = g_list_append(diphone_list, "z-ah");
	diphone_list = g_list_append(diphone_list, "ah-t");
	diphone_list = g_list_append(diphone_list, "t-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");
	diphone_list = g_list_append(diphone_list, "r-z");
    }	
    
    
    //------------------------------------------------------------------
    // W Words
    //------------------------------------------------------------------
    
    
    //world W_UH UH_R R_L L_D
	if (g_strcmp0(word,"world")==0) {
	diphone_list = g_list_append(diphone_list, "w-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");
	diphone_list = g_list_append(diphone_list, "r-l");
	diphone_list = g_list_append(diphone_list, "l-d");	
	//phone_list = g_list_append(phone_list, "w-uh");
	//phone_list = g_list_append(phone_list, "r-r");	
	//phone_list = g_list_append(phone_list, "l-d");	 
    }
    
    //walk W_AO AO_K
    if (g_strcmp0(word,"walk")==0) {	
	diphone_list = g_list_append(diphone_list, "w-ao");
	diphone_list = g_list_append(diphone_list, "ao-k");
	}	
    
    //warning W_AO AO_R R_N N_IH IH_NG
    if (g_strcmp0(word,"warning")==0) {	
	diphone_list = g_list_append(diphone_list, "w-ao");
	diphone_list = g_list_append(diphone_list, "ao-r");
	diphone_list = g_list_append(diphone_list, "r-n");
	diphone_list = g_list_append(diphone_list, "n-ih");			
	diphone_list = g_list_append(diphone_list, "ih-ng");
	}	
    
    //weather W_EH EH_DH DH_UH UH_R
    if (g_strcmp0(word,"weather")==0) {	
	diphone_list = g_list_append(diphone_list, "w-eh");
	diphone_list = g_list_append(diphone_list, "eh-dh");
	diphone_list = g_list_append(diphone_list, "dh-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");	
    }	
    
    //wedding W_EH EH_D D_IH IH_NG
    if (g_strcmp0(word,"wedding")==0) {	
	diphone_list = g_list_append(diphone_list, "w-eh");
	diphone_list = g_list_append(diphone_list, "eh-d");
	diphone_list = g_list_append(diphone_list, "d-ih");
	diphone_list = g_list_append(diphone_list, "ih-ng");
    }	
    
    //wibblewobble W_IH IH_B B_AH AH_L L_W W_AA AA_B B_AH AH_L
    if (g_strcmp0(word,"wibblewobble")==0) {	
	diphone_list = g_list_append(diphone_list, "w-ih");
	diphone_list = g_list_append(diphone_list, "ih-b");
	diphone_list = g_list_append(diphone_list, "b-ah");
	diphone_list = g_list_append(diphone_list, "ah-l");			
	diphone_list = g_list_append(diphone_list, "l-w");	
	diphone_list = g_list_append(diphone_list, "w-aa");			
	diphone_list = g_list_append(diphone_list, "aa-b");
	diphone_list = g_list_append(diphone_list, "b-ah");			
	diphone_list = g_list_append(diphone_list, "ah-l");	 	    
    }	
    
    //wife W_AA AA_IY IY_F
    if (g_strcmp0(word,"wife")==0) {	
	diphone_list = g_list_append(diphone_list, "w-aa");
	diphone_list = g_list_append(diphone_list, "aa-iy");
	diphone_list = g_list_append(diphone_list, "iy-f");		    
    }	
    
    //wind W_AA AA_IY IY_N N_D
    if (g_strcmp0(word,"wind")==0) {	
	diphone_list = g_list_append(diphone_list, "w-aa");
	diphone_list = g_list_append(diphone_list, "aa-iy");
	diphone_list = g_list_append(diphone_list, "iy-n");
	diphone_list = g_list_append(diphone_list, "n-d");
    }	
    
    //work W_UH UH_R R_K
    if (g_strcmp0(word,"work")==0) {	
	diphone_list = g_list_append(diphone_list, "w-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");
	diphone_list = g_list_append(diphone_list, "r-k");
    }	
    
    //workman W_UH UH_R R_K K_M M_AH AH_N
    if (g_strcmp0(word,"workman")==0) {	
	diphone_list = g_list_append(diphone_list, "w-uh");
	diphone_list = g_list_append(diphone_list, "uh-r");
	diphone_list = g_list_append(diphone_list, "r-k");
	diphone_list = g_list_append(diphone_list, "k-m");			
	diphone_list = g_list_append(diphone_list, "m-ah");	
	diphone_list = g_list_append(diphone_list, "ah-n");	
    }	
    
    //------------------------------------------------------------------
    // X Words
    //------------------------------------------------------------------
	//if (g_strcmp0(word,"")==0) {	
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	    
    //}	
	//------------------------------------------------------------------
    // Y Words
    //------------------------------------------------------------------
	 //if (g_strcmp0(word,"")==0) {	
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	    
    //}	
	//------------------------------------------------------------------
    // Z Words
    //------------------------------------------------------------------ 
	
	//zoo Z_UW 
	if (g_strcmp0(word,"zoo")==0) {	
	diphone_list = g_list_append(diphone_list, "z-uw");
    }	
    //if (g_strcmp0(word,"")==0) {	
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	
	//diphone_list = g_list_append(diphone_list, "");			
	//diphone_list = g_list_append(diphone_list, "");	    
    //}	
	
	return diphone_list;
}	

