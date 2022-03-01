/***************************************************************************
 * GPL v3.0 license (see license document distributed with this software)
 * Word to phoneme converter 
 * Author: crispinalan@gmail.com
 ***************************************************************************/

#include <gtk/gtk.h> 
#include "word2phone.h"

GList* word_to_phonemes(const char* word_str) {
	
	GList *phone_list=NULL;
	
	char* word = g_ascii_strdown(word_str, -1); //covert to lower case
		
	//------------------------------------------------------------------
	//A words
	//------------------------------------------------------------------
		
	if (g_strcmp0(word,"and")==0) {
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "d");  
    }
	
	if (g_strcmp0(word,"anniversary")==0) {
	phone_list = g_list_append(phone_list, "ae");
	phone_list = g_list_append(phone_list, "pause2");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "v");
	phone_list = g_list_append(phone_list, "er"); 
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "s"); 
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "iy"); 
	phone_list = g_list_append(phone_list, "pause0");	    
    }
	
	if (g_strcmp0(word,"april")==0) {
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "p");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");  
	phone_list = g_list_append(phone_list, "l");    
    }
   
    if (g_strcmp0(word,"august")==0) {
	phone_list = g_list_append(phone_list, "aa");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "g");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "s");  
	phone_list = g_list_append(phone_list, "t");    
    }
		
	if (g_strcmp0(word,"allday")==0) {
	phone_list = g_list_append(phone_list, "ao");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "d");
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause2");	    
    }
    	
	if (g_strcmp0(word,"activity")==0) {
	phone_list = g_list_append(phone_list, "ae");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "v"); 
	phone_list = g_list_append(phone_list, "ah"); 
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "t"); 
	phone_list = g_list_append(phone_list, "iy"); 
	phone_list = g_list_append(phone_list, "pause0");	    
    }
	
	if (g_strcmp0(word,"appointment")==0) {
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "p");
	phone_list = g_list_append(phone_list, "oy");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "t"); 
	phone_list = g_list_append(phone_list, "m"); 
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "t");     
    }
			
	if (g_strcmp0(word,"allotment")==0) {
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "aa");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "m"); 
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "t"); 	    
    }
       
    if (g_strcmp0(word,"alert")==0) {
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "t");	
    }
		
	if (g_strcmp0(word,"airport")==0) {
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "p");
	phone_list = g_list_append(phone_list, "ao");
	phone_list = g_list_append(phone_list, "pause2");
	phone_list = g_list_append(phone_list, "r"); 
	phone_list = g_list_append(phone_list, "t");		    
    }
   
    if (g_strcmp0(word,"agenda")==0) {
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "jh");
	phone_list = g_list_append(phone_list, "eh");	
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "d"); 
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");		    
    }
   
	if (g_strcmp0(word,"attend")==0) {
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "eh");	
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "d");		    
    }
    
    if (g_strcmp0(word,"agent")==0) {
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "jh");
	phone_list = g_list_append(phone_list, "ah");	
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "t");		    
    }
	
	//------------------------------------------------------------------
	//B words
	//------------------------------------------------------------------
	
	if (g_strcmp0(word,"bank")==0) {
	phone_list = g_list_append(phone_list, "b");
	phone_list = g_list_append(phone_list, "ae");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "ng");
	phone_list = g_list_append(phone_list, "k");	    
    }
		
	if (g_strcmp0(word,"banquet")==0) {
	phone_list = g_list_append(phone_list, "b");
	phone_list = g_list_append(phone_list, "ae");
	phone_list = g_list_append(phone_list, "pause1");	
	phone_list = g_list_append(phone_list, "ng");
	phone_list = g_list_append(phone_list, "k");  
	phone_list = g_list_append(phone_list, "w");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "t");
    }
	
	if (g_strcmp0(word,"barbershop")==0) {
	phone_list = g_list_append(phone_list, "b");
	phone_list = g_list_append(phone_list, "aa");
	phone_list = g_list_append(phone_list, "pause1");	
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "b");  
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "sh");
	phone_list = g_list_append(phone_list, "aa");
	phone_list = g_list_append(phone_list, "pause2");  
	phone_list = g_list_append(phone_list, "p"); 
    }
	
	if (g_strcmp0(word,"buns")==0) {
	phone_list = g_list_append(phone_list, "b");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause1");	
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "z");  
    }

	if (g_strcmp0(word,"builder")==0) {
	phone_list = g_list_append(phone_list, "b");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause1");	
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "d");  
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause0");     
    }
    
    if (g_strcmp0(word,"business")==0) {
	phone_list = g_list_append(phone_list, "b");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause1");	
	phone_list = g_list_append(phone_list, "z");
	phone_list = g_list_append(phone_list, "n");  
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "s");      
    }

    if (g_strcmp0(word,"bye")==0) {
	phone_list = g_list_append(phone_list, "b");
	phone_list = g_list_append(phone_list, "ay");
	phone_list = g_list_append(phone_list, "pause1");			     
    }

	if (g_strcmp0(word,"bill")==0) {
	phone_list = g_list_append(phone_list, "b");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause1");	
	phone_list = g_list_append(phone_list, "l");	     
    }
	
	if (g_strcmp0(word,"birthday")==0) {
	phone_list = g_list_append(phone_list, "b");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause1");	
	phone_list = g_list_append(phone_list, "th");
	phone_list = g_list_append(phone_list, "d");  
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause2");     
    }
	
	if (g_strcmp0(word,"book")==0) {
	phone_list = g_list_append(phone_list, "b");
	phone_list = g_list_append(phone_list, "uh");
	phone_list = g_list_append(phone_list, "pause1");	
	phone_list = g_list_append(phone_list, "k");	     
    }
	
	//------------------------------------------------------------------
	//C words
	//------------------------------------------------------------------
	
	if (g_strcmp0(word,"cancelled")==0) {
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "ae");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "ah"); 
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "d"); 	     
    }
  
	if (g_strcmp0(word,"car")==0) {
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "aa");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "r");	
    }
  
    if (g_strcmp0(word,"cake")==0) {
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "k");	
    }
    
    
    if (g_strcmp0(word,"contact")==0) {
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "aa");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "ae"); 
	phone_list = g_list_append(phone_list, "pause2"); 
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "t"); 	     
    }
   
	if (g_strcmp0(word,"code")==0) {
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "ow");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "d");	
     }
   
     if (g_strcmp0(word,"cooking")==0) {
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "uh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "ih");	 
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "ng");		     
    }
   	
	if (g_strcmp0(word,"christmas")==0) {
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "m"); 
	phone_list = g_list_append(phone_list, "ah"); 
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "s"); 	     
    }
	
	if (g_strcmp0(word,"calendar")==0) {
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "ae");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "d"); 
	phone_list = g_list_append(phone_list, "er"); 
	phone_list = g_list_append(phone_list, "pause0");	     
    }
    
    if (g_strcmp0(word,"castle")==0) {
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "ae");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "l"); 	     
    }
  
    if (g_strcmp0(word,"celebrate")==0) {
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "ah");	
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "b");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause2");
	phone_list = g_list_append(phone_list, "t");
    }
    
     if (g_strcmp0(word,"celebration")==0) {
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause2");
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "ah");	
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "b");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "sh"); 
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "n");	     
    }
    
    //CLINIC  K L IH1 N IH0 K
    if (g_strcmp0(word,"clinic")==0) {
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "k");	     
    }
  
    if (g_strcmp0(word,"charity")==0) {
	phone_list = g_list_append(phone_list, "ch");
	phone_list = g_list_append(phone_list, "eh");	
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "r");	
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "t"); 
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause0");	     
    }
		
	if (g_strcmp0(word,"cricket")==0) {
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "ih");	
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "k");	
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "t"); 		     
    }
	
	if (g_strcmp0(word,"cycle")==0) {
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "ay");		
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "k");	
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "l"); 		     
    }
	
	
	if (g_strcmp0(word,"critical")==0) {
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "ih");	
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "t");	
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "k"); 
	phone_list = g_list_append(phone_list, "ah"); 
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "l"); 		     
    }
	
	
	//------------------------------------------------------------------
	//D words
	//------------------------------------------------------------------
	
	if (g_strcmp0(word,"december")==0) {
	phone_list = g_list_append(phone_list, "d");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "m"); 
	phone_list = g_list_append(phone_list, "b"); 
	phone_list = g_list_append(phone_list, "er"); 
	phone_list = g_list_append(phone_list, "pause0");	    
    }

	if (g_strcmp0(word,"dentist")==0) {
	phone_list = g_list_append(phone_list, "d");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "s"); 
	phone_list = g_list_append(phone_list, "t"); 	    
    }
 
    if (g_strcmp0(word,"development")==0) {
	phone_list = g_list_append(phone_list, "d");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "v");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "l"); 
	phone_list = g_list_append(phone_list, "ah"); 
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "p");
	phone_list = g_list_append(phone_list, "m");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "t"); 		    
    }
   
    if (g_strcmp0(word,"doctor")==0) {
	phone_list = g_list_append(phone_list, "d");
	phone_list = g_list_append(phone_list, "aa");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause0"); 	     
    }
    
    if (g_strcmp0(word,"delivery")==0) {
	phone_list = g_list_append(phone_list, "d");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "v");
	phone_list = g_list_append(phone_list, "er");	
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause0"); 	     
    }
      
	if (g_strcmp0(word,"day")==0) {
	phone_list = g_list_append(phone_list, "d");
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause1");
    }
  
	//------------------------------------------------------------------
	//E words
	//------------------------------------------------------------------
	
	if (g_strcmp0(word,"event")==0) {
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "v");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "t"); 	     
    }
          
	if (g_strcmp0(word,"events")==0) {
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "v");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "t"); 
	phone_list = g_list_append(phone_list, "s"); 	    
    }
      
    if (g_strcmp0(word,"eighth")==0) {
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "th");	   
    }
      
    if (g_strcmp0(word,"eleventh")==0) {
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "v");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "th");     
    }
     
    if (g_strcmp0(word,"eighteenth")==0) {
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "th");
    }
    
	if (g_strcmp0(word,"eight")==0) {
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "t");	  
    }
	
    if (g_strcmp0(word,"eleven")==0) {
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "v");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "n"); 	     
    }
 
    if (g_strcmp0(word,"eighteen")==0) {
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");	    
    }
	
	if (g_strcmp0(word,"easterday")==0) {
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "d"); 
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause2"); 	 	     
    }
   
    if (g_strcmp0(word,"easter")==0) {
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause0");
    }
   
    if (g_strcmp0(word,"energy")==0) {
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "er");	
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "jh"); 
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause0"); 	 	     
    }
   
    if (g_strcmp0(word,"estate")==0) {
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "ey");	
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "t");	 	 	     
    }
		
	//------------------------------------------------------------------
	//F words
	//------------------------------------------------------------------
	
	if (g_strcmp0(word,"february")==0) {
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "b");
	phone_list = g_list_append(phone_list, "y");
	phone_list = g_list_append(phone_list, "ah"); 
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "w"); 
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause2"); 
	phone_list = g_list_append(phone_list, "r"); 
	phone_list = g_list_append(phone_list, "iy"); 
	phone_list = g_list_append(phone_list, "pause0");    
    }
    
   
	if (g_strcmp0(word,"four")==0) {
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "ao");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "r");	    
    }
		
	
	if (g_strcmp0(word,"five")==0) {
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "ay");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "v");	    
    }
      
  
    if (g_strcmp0(word,"fourteen")==0) {
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "ao");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause1"); 
	phone_list = g_list_append(phone_list, "n"); 	     
    }
    
    if (g_strcmp0(word,"fifteen")==0) {
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause1"); 
	phone_list = g_list_append(phone_list, "n"); 	     
    }
   
    if (g_strcmp0(word,"forty")==0) {
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "ao");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause0");
    }
   
    if (g_strcmp0(word,"fifty")==0) {
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause0");
    }

	if (g_strcmp0(word,"first")==0) {
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "t");	     
    }

	if (g_strcmp0(word,"fourth")==0) {
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "ao");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "th");	    
    }
    
	if (g_strcmp0(word,"fifth")==0) {
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "th");	    
    }
	
	if (g_strcmp0(word,"fourteenth")==0) {
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "ao");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause1"); 
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "th"); 	    
    }
	
	if (g_strcmp0(word,"fifteenth")==0) {
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause1"); 
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "th");
    }
	
	if (g_strcmp0(word,"friday")==0) {
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "ay");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "d");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause0");     
    }
	
	if (g_strcmp0(word,"family")==0) {
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "ae");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "m");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "l"); 
	phone_list = g_list_append(phone_list, "iy"); 
	phone_list = g_list_append(phone_list, "pause0");	     
    }
    
    if (g_strcmp0(word,"father")==0) {
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "aa");
	phone_list = g_list_append(phone_list, "pause1");	
	phone_list = g_list_append(phone_list, "dh");	
	phone_list = g_list_append(phone_list, "er"); 	
	phone_list = g_list_append(phone_list, "pause0");
	//phone_list = g_list_append(phone_list, "pause0");	     
    }
       
    if (g_strcmp0(word,"fathers")==0) {
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "aa");
	phone_list = g_list_append(phone_list, "pause1");	
	phone_list = g_list_append(phone_list, "dh");	
	phone_list = g_list_append(phone_list, "er"); 	
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "z");	     
    }
    
	if (g_strcmp0(word,"food")==0) {
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "uw");
	phone_list = g_list_append(phone_list, "uw");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "d");		
    }
	
	if (g_strcmp0(word,"film")==0) {
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "m");	
    }
	
	if (g_strcmp0(word,"funeral")==0) {
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "y");
	phone_list = g_list_append(phone_list, "uw");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "l"); 	   
    }
  
    if (g_strcmp0(word,"football")==0) {
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "uh");	
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "b");
	phone_list = g_list_append(phone_list, "ao");
	phone_list = g_list_append(phone_list, "pause2"); 
	phone_list = g_list_append(phone_list, "l");	 	   
    }
	
	if (g_strcmp0(word,"friend")==0) {
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "d"); 	   
    }
	
	//------------------------------------------------------------------
	//G words
	//------------------------------------------------------------------
	
	if (g_strcmp0(word,"garden")==0) {
	phone_list = g_list_append(phone_list, "g");
	phone_list = g_list_append(phone_list, "aa");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "d");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "n"); 	    
    }

	if (g_strcmp0(word,"go")==0) {
	phone_list = g_list_append(phone_list, "g");
	phone_list = g_list_append(phone_list, "ow");
	phone_list = g_list_append(phone_list, "pause1");
    }
	
	
	if (g_strcmp0(word,"goodbye")==0) {
	phone_list = g_list_append(phone_list, "g");
	phone_list = g_list_append(phone_list, "uh");
	phone_list = g_list_append(phone_list, "uh");
	phone_list = g_list_append(phone_list, "pause2");
	phone_list = g_list_append(phone_list, "d");
	phone_list = g_list_append(phone_list, "b");
	phone_list = g_list_append(phone_list, "ay");
	phone_list = g_list_append(phone_list, "pause1"); 		    
    }
		
	if (g_strcmp0(word,"good")==0) {
	phone_list = g_list_append(phone_list, "g");
	phone_list = g_list_append(phone_list, "uh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "d");
    }
	
	if (g_strcmp0(word,"gas")==0) {
	phone_list = g_list_append(phone_list, "g");
	phone_list = g_list_append(phone_list, "aa");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "ae1");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "s");
    }
		
	
	//------------------------------------------------------------------
	//H words
	//------------------------------------------------------------------
	
	 if (g_strcmp0(word,"hairdresser")==0) {
	phone_list = g_list_append(phone_list, "hh");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "d");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause2");
	phone_list = g_list_append(phone_list, "s"); 
	phone_list = g_list_append(phone_list, "er"); 
	phone_list = g_list_append(phone_list, "pause0");  
    }
		
	if (g_strcmp0(word,"have")==0) {
	phone_list = g_list_append(phone_list, "hh");
	phone_list = g_list_append(phone_list, "ae");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "v");	   
    }
      
     if (g_strcmp0(word,"health")==0) {
	phone_list = g_list_append(phone_list, "hh");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "");
	phone_list = g_list_append(phone_list, "th");	   
    }
       
    if (g_strcmp0(word,"heating")==0) {
	phone_list = g_list_append(phone_list, "hh");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "ng");    
    }
	
	if (g_strcmp0(word,"hello")==0) {
	phone_list = g_list_append(phone_list, "hh");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "ow");
	phone_list = g_list_append(phone_list, "pause1");    
    }
	
	if (g_strcmp0(word,"holiday")==0) {
	phone_list = g_list_append(phone_list, "hh");
	phone_list = g_list_append(phone_list, "aa");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "d"); 
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause2"); 	    
    }
   
    if (g_strcmp0(word,"home")==0) {
	phone_list = g_list_append(phone_list, "hh");
	phone_list = g_list_append(phone_list, "ow");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "m");	
    }
	
	if (g_strcmp0(word,"hospital")==0) {
	phone_list = g_list_append(phone_list, "hh");
	phone_list = g_list_append(phone_list, "aa");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "p");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause2"); 
	phone_list = g_list_append(phone_list, "t"); 
	phone_list = g_list_append(phone_list, "ah"); 
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "l");
    }
	
	if (g_strcmp0(word,"house")==0) {
	phone_list = g_list_append(phone_list, "hh");
	phone_list = g_list_append(phone_list, "aw");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "s");	
    }
		
	if (g_strcmp0(word,"high")==0) {
	phone_list = g_list_append(phone_list, "hh");
	phone_list = g_list_append(phone_list, "ay");	
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "ay");		
    }
	
		
	//------------------------------------------------------------------
	//I words
	//------------------------------------------------------------------
	
	if (g_strcmp0(word,"interview")==0) {
	phone_list = g_list_append(phone_list, "ih");	
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "v"); 
	phone_list = g_list_append(phone_list, "ay"); 
	phone_list = g_list_append(phone_list, "uw");
	phone_list = g_list_append(phone_list, "pause2");
    }
    
    if (g_strcmp0(word,"insurance")==0) {
	phone_list = g_list_append(phone_list, "ih");	
	phone_list = g_list_append(phone_list, "pause2");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "sh");
	phone_list = g_list_append(phone_list, "uh");
	phone_list = g_list_append(phone_list, "pause1"); 
	phone_list = g_list_append(phone_list, "r"); 
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "s");
    }
	
	
	//------------------------------------------------------------------
	//J words
	//------------------------------------------------------------------
	
	if (g_strcmp0(word,"january")==0) {
	phone_list = g_list_append(phone_list, "jh");
	phone_list = g_list_append(phone_list, "ae");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "y");
	phone_list = g_list_append(phone_list, "uw");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause2");
	phone_list = g_list_append(phone_list, "r"); 
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause0");     
    }
    
    if (g_strcmp0(word,"july")==0) {
	phone_list = g_list_append(phone_list, "jh");
	phone_list = g_list_append(phone_list, "uw");
	phone_list = g_list_append(phone_list, "pause2");
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "ay"); 
	phone_list = g_list_append(phone_list, "pause1");   
    }
    
	if (g_strcmp0(word,"june")==0) {
	phone_list = g_list_append(phone_list, "jh");
	phone_list = g_list_append(phone_list, "uw");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");	   
    }
	
	//------------------------------------------------------------------
	//K words
	//------------------------------------------------------------------
	
	if (g_strcmp0(word,"known")==0) {
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "ow");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");	   
    }
	
	
	//------------------------------------------------------------------
	//L words
	//------------------------------------------------------------------
	
	if (g_strcmp0(word,"letter")==0) {
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause0");	   
    }
	
	if (g_strcmp0(word,"leisure")==0) {
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "zh");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause0");	   
    }
	
	if (g_strcmp0(word,"lift")==0) {
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "t");		   
    }
    
    if (g_strcmp0(word,"linux")==0) {
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "s");	   
    }
   
    if (g_strcmp0(word,"lunch")==0) {
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "ch");		   
    }
   
    if (g_strcmp0(word,"low")==0) {
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "ow");
	phone_list = g_list_append(phone_list, "pause1");			   
    }
   
	//------------------------------------------------------------------
	//M words
	//------------------------------------------------------------------
	
	if (g_strcmp0(word,"march")==0) {
	phone_list = g_list_append(phone_list, "m");
	phone_list = g_list_append(phone_list, "aa");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "ch");    
    }
        
    if (g_strcmp0(word,"may")==0) {
	phone_list = g_list_append(phone_list, "m");
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause1");	   
    }
   
    if (g_strcmp0(word,"memo")==0) {
	phone_list = g_list_append(phone_list, "m");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "m");
	phone_list = g_list_append(phone_list, "ow");	
	phone_list = g_list_append(phone_list, "pause2"); 	   
    }
     
	if (g_strcmp0(word,"monday")==0) {
	phone_list = g_list_append(phone_list, "m");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "d");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause0"); 	   
    }
	
	
	if (g_strcmp0(word,"many")==0) {
	phone_list = g_list_append(phone_list, "m");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause0");	     
    }
   
   
    if (g_strcmp0(word,"month")==0) {
	phone_list = g_list_append(phone_list, "m");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "th");	     
    }
	
	//event words
	
	if (g_strcmp0(word,"match")==0) {
	phone_list = g_list_append(phone_list, "m");
	phone_list = g_list_append(phone_list, "ae");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "ch");	     
    }
		
	if (g_strcmp0(word,"meal")==0) {
	phone_list = g_list_append(phone_list, "m");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "l");	     
    }
    
	if (g_strcmp0(word,"medical")==0) {
	phone_list = g_list_append(phone_list, "m");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "d");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "k"); 
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "l"); 	    
    }
	
	if (g_strcmp0(word,"meeting")==0) {
	phone_list = g_list_append(phone_list, "m");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "ng"); 	    
    }
      
	if (g_strcmp0(word,"move")==0) {
	phone_list = g_list_append(phone_list, "m");
	phone_list = g_list_append(phone_list, "uw");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "v");		    
    }
    
	if (g_strcmp0(word,"movie")==0) {
	phone_list = g_list_append(phone_list, "m");
	phone_list = g_list_append(phone_list, "uw");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "v");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause0");		    
    }
	
	if (g_strcmp0(word,"music")==0) {
	phone_list = g_list_append(phone_list, "m");
	phone_list = g_list_append(phone_list, "y");
	phone_list = g_list_append(phone_list, "uw");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "z");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "k");  	    
    }
   
    if (g_strcmp0(word,"milkman")==0) {
	phone_list = g_list_append(phone_list, "m");
	phone_list = g_list_append(phone_list, "ih");	
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "m");
	phone_list = g_list_append(phone_list, "ae");
	phone_list = g_list_append(phone_list, "pause2");
	phone_list = g_list_append(phone_list, "n");  	    
    }
   
     if (g_strcmp0(word,"mince")==0) {
	phone_list = g_list_append(phone_list, "m");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "s");	     
    }
    
	
	if (g_strcmp0(word,"mystic")==0) {
	phone_list = g_list_append(phone_list, "m");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "k");		    
    }
	
	 if (g_strcmp0(word,"mother")==0) {
	phone_list = g_list_append(phone_list, "m");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "dh");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause0");		    
    }
	
    
    if (g_strcmp0(word,"mothers")==0) {
	phone_list = g_list_append(phone_list, "m");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "dh");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "z"); 	    
    }
	
	//------------------------------------------------------------------
	//N words
	//------------------------------------------------------------------
	
	if (g_strcmp0(word,"netflix")==0) {
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "f");
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "k"); 
	//phone_list = g_list_append(phone_list, "s");	    
    }
	
	
    if (g_strcmp0(word,"not")==0) {
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "aa");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "t");	    
    }
  
	if (g_strcmp0(word,"november")==0) {
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "ow");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "v");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "m"); 
	phone_list = g_list_append(phone_list, "b"); 
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause0"); 	     
    }
	
	if (g_strcmp0(word,"ninth")==0) {
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "ay");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "th");
	phone_list = g_list_append(phone_list, "th");	     
    }
	
	if (g_strcmp0(word,"nineteenth")==0) {
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "ay");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause1"); 
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "th"); 	     
    }
	
	if (g_strcmp0(word,"nine")==0) {
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "ay");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "pause0");	    
    }
		
	if (g_strcmp0(word,"nineteen")==0) {
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "ay");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "iy"); 
	phone_list = g_list_append(phone_list, "n"); 	     
    }
			
	if (g_strcmp0(word,"no")==0) {
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "ow"); 
	phone_list = g_list_append(phone_list, "pause2");  
    }
		
	
	//------------------------------------------------------------------
	//O words
	//------------------------------------------------------------------
	
	if (g_strcmp0(word,"october")==0) {
	phone_list = g_list_append(phone_list, "aa");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "ow");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "b"); 
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause0"); 	     
    }
	
		
	if (g_strcmp0(word,"one")==0) {
	phone_list = g_list_append(phone_list, "w");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "pause0");	    
    }
	
		
	if (g_strcmp0(word,"on")==0) {
	phone_list = g_list_append(phone_list, "aa");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");	     
    }
	
		
	if (g_strcmp0(word,"o")==0) {
	phone_list = g_list_append(phone_list, "ow");
	phone_list = g_list_append(phone_list, "pause1");	    
    }
		
	if (g_strcmp0(word,"online")==0) {
	phone_list = g_list_append(phone_list, "ao");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "ay");
	phone_list = g_list_append(phone_list, "pause2");
	phone_list = g_list_append(phone_list, "n"); 	    
    }
       
    if (g_strcmp0(word,"operation")==0) {
	phone_list = g_list_append(phone_list, "aa");
	phone_list = g_list_append(phone_list, "pause2");
	phone_list = g_list_append(phone_list, "p");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause0");	
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause1"); 
	phone_list = g_list_append(phone_list, "sh"); 
	phone_list = g_list_append(phone_list, "ah"); 
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "n"); 	    
    }
    
	if (g_strcmp0(word,"overlapping")==0) {
	phone_list = g_list_append(phone_list, "ow");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "v");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "ae");
	phone_list = g_list_append(phone_list, "pause2"); 
	phone_list = g_list_append(phone_list, "p"); 
	phone_list = g_list_append(phone_list, "ih"); 
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "ng"); 	    
    }
	
	//------------------------------------------------------------------
	//P words
	//------------------------------------------------------------------
	
		
	if (g_strcmp0(word,"pause")==0) {	
	phone_list = g_list_append(phone_list, "pause2");
	phone_list = g_list_append(phone_list, "pause2");	
    }
	
	
	if (g_strcmp0(word,"party")==0) {
	phone_list = g_list_append(phone_list, "p");
	phone_list = g_list_append(phone_list, "aa");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "iy"); 	
	phone_list = g_list_append(phone_list, "pause0");   
    }
	
	if (g_strcmp0(word,"parcel")==0) {
	phone_list = g_list_append(phone_list, "p");
	phone_list = g_list_append(phone_list, "aa");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "ah"); 	
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "l");    
    }
	
	if (g_strcmp0(word,"pay")==0) {
	phone_list = g_list_append(phone_list, "p");
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause1");
    }
    
    if (g_strcmp0(word,"pie")==0) {
	phone_list = g_list_append(phone_list, "p");
	phone_list = g_list_append(phone_list, "ay");
	phone_list = g_list_append(phone_list, "pause1");
    }
   
    if (g_strcmp0(word,"pies")==0) {
	phone_list = g_list_append(phone_list, "p");
	phone_list = g_list_append(phone_list, "ay");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "z");
    }
			
	if (g_strcmp0(word,"payment")==0) {
	phone_list = g_list_append(phone_list, "p");
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "m");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "t"); 	    
    }
    
    if (g_strcmp0(word,"pension")==0) {
	phone_list = g_list_append(phone_list, "p");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "sh");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "n"); 	 	    
    }
   
	if (g_strcmp0(word,"personal")==0) {
	phone_list = g_list_append(phone_list, "p");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "l"); 	     
    }
   
    if (g_strcmp0(word,"phone")==0) {
	phone_list = g_list_append(phone_list, "p");
	phone_list = g_list_append(phone_list, "ow");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");	     
    }
   
	if (g_strcmp0(word,"picnic")==0) {
	phone_list = g_list_append(phone_list, "p");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause2"); 
	phone_list = g_list_append(phone_list, "k"); 	     
    }
	
	if (g_strcmp0(word,"priority")==0) {
	phone_list = g_list_append(phone_list, "p");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "ay");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "ao");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "r"); 
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "t"); 
	phone_list = g_list_append(phone_list, "iy"); 
	phone_list = g_list_append(phone_list, "pause0");
	    
    }
	
	if (g_strcmp0(word,"project")==0) {
	phone_list = g_list_append(phone_list, "p");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "aa");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "jh");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "k"); 
	phone_list = g_list_append(phone_list, "t"); 	    
    }
	
	if (g_strcmp0(word,"point")==0) {
	phone_list = g_list_append(phone_list, "p");
	phone_list = g_list_append(phone_list, "oy");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "pause0");	     
    }
   
    if (g_strcmp0(word,"post")==0) {
	phone_list = g_list_append(phone_list, "p");
	phone_list = g_list_append(phone_list, "ow");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "t");		     
    }
		
	
	//------------------------------------------------------------------
	//Q Words
	//------------------------------------------------------------------
		
	
	
	//------------------------------------------------------------------
	//R words
	//------------------------------------------------------------------
	
	if (g_strcmp0(word,"red")==0) {
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");	
	phone_list = g_list_append(phone_list, "d");
    }
	
	if (g_strcmp0(word,"reminder")==0) {
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause0");
	
	phone_list = g_list_append(phone_list, "m");
	//phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "pause0");			
	phone_list = g_list_append(phone_list, "ay");
	phone_list = g_list_append(phone_list, "ay");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "n");	 
	phone_list = g_list_append(phone_list, "d"); 
	phone_list = g_list_append(phone_list, "d"); 
	phone_list = g_list_append(phone_list, "er");
	//phone_list = g_list_append(phone_list, "er");  
	phone_list = g_list_append(phone_list, "pause0");	     
    }
    
      
    if (g_strcmp0(word,"remember")==0) {
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "m");	
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "m"); 	 
	phone_list = g_list_append(phone_list, "b"); 
	phone_list = g_list_append(phone_list, "er");	  
	phone_list = g_list_append(phone_list, "pause0");	     
    }
       	
	if (g_strcmp0(word,"radio")==0) {
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "d");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "ow");
	phone_list = g_list_append(phone_list, "pause2"); 	    
    }

	if (g_strcmp0(word,"restaurant")==0) {
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "aa");
	phone_list = g_list_append(phone_list, "pause2"); 
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "t"); 	    
    }
		
	if (g_strcmp0(word,"repair")==0) {
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "p");	
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1"); 
	phone_list = g_list_append(phone_list, "r");	    
    }
    
	//------------------------------------------------------------------
	//S words
	//------------------------------------------------------------------
	
	if (g_strcmp0(word,"september")==0) {
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "p");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1"); 
	phone_list = g_list_append(phone_list, "m"); 
	phone_list = g_list_append(phone_list, "b"); 
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause0");     
    }
	
	
	if (g_strcmp0(word,"second")==0) {
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "d"); 	    
    }
		
	if (g_strcmp0(word,"sixth")==0) {
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "th"); 	     
    }
	
	if (g_strcmp0(word,"sixteenth")==0) {
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "t"); 
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause1"); 
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "th"); 	    
    }
  
	if (g_strcmp0(word,"seventh")==0) {
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "v");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "th"); 	     
    }
	
	if (g_strcmp0(word,"seventeenth")==0) {
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "v");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "t"); 
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause1"); 
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "th");     
    }
		
	if (g_strcmp0(word,"six")==0) {
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "s");	     
    }
		
	if (g_strcmp0(word,"seven")==0) {
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "v");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "n"); 	    
    }
		
	if (g_strcmp0(word,"sixteen")==0) {
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "t"); 
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause1"); 
	phone_list = g_list_append(phone_list, "n"); 	     
    }
	
	if (g_strcmp0(word,"seventeen")==0) {
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "v");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "t"); 
	phone_list = g_list_append(phone_list, "iy"); 
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n"); 	    
    }
			
	if (g_strcmp0(word,"sunday")==0) {
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "d");
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause2");
    }
			
	if (g_strcmp0(word,"saturday")==0) {
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "ae");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "d"); 
	phone_list = g_list_append(phone_list, "iy"); 
	phone_list = g_list_append(phone_list, "pause0");	    
    }
	
	if (g_strcmp0(word,"service")==0) {
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "v");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "s"); 	    
    }
	
	if (g_strcmp0(word,"shop")==0) {
	phone_list = g_list_append(phone_list, "sh");
	phone_list = g_list_append(phone_list, "aa");
	phone_list = g_list_append(phone_list, "pause2");
	phone_list = g_list_append(phone_list, "p");
	//phone_list = g_list_append(phone_list, "p");
    }
	
	if (g_strcmp0(word,"shopping")==0) {
	phone_list = g_list_append(phone_list, "sh");
	phone_list = g_list_append(phone_list, "aa");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "p");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "ng"); 	    
    }
		
	if (g_strcmp0(word,"special")==0) {
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "p");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "sh");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "l"); 	     
    }
   
    if (g_strcmp0(word,"sport")==0) {
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "p");
	phone_list = g_list_append(phone_list, "ao");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "t");	     
    }
  
	if (g_strcmp0(word,"station")==0) {
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "sh");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "n"); 	  
    }
		
	if (g_strcmp0(word,"subscription")==0) {
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "b");
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "k"); 
	phone_list = g_list_append(phone_list, "r"); 
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause1"); 
	phone_list = g_list_append(phone_list, "p"); 
	phone_list = g_list_append(phone_list, "sh"); 
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "n");     
    }
   
    if (g_strcmp0(word,"supermarket")==0) {
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "uw");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "p");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "m"); 
	phone_list = g_list_append(phone_list, "aa");
	phone_list = g_list_append(phone_list, "pause2"); 
	phone_list = g_list_append(phone_list, "r"); 
	phone_list = g_list_append(phone_list, "k"); 
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "t");     
    }
    
    if (g_strcmp0(word,"solicitor")==0) {
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause1"); 
	phone_list = g_list_append(phone_list, "s"); 
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause0"); 	    
    }
 
	if (g_strcmp0(word,"system")==0) {
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause1");	
	phone_list = g_list_append(phone_list, "s");
	phone_list = g_list_append(phone_list, "t"); 
	phone_list = g_list_append(phone_list, "ah"); 	
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "m"); 	    
    }
  
    if (g_strcmp0(word,"show")==0) {
	phone_list = g_list_append(phone_list, "sh");	
	phone_list = g_list_append(phone_list, "ow");
	phone_list = g_list_append(phone_list, "pause1");		     
    }
   
    if (g_strcmp0(word,"seed")==0) {
	phone_list = g_list_append(phone_list, "s");	
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "d");		     
    }
	
	 if (g_strcmp0(word,"seed")==0) {
	phone_list = g_list_append(phone_list, "s");	
	phone_list = g_list_append(phone_list, "ow");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "ng");		     
    }
	
	
	//------------------------------------------------------------------
	//T words
	//------------------------------------------------------------------
	
	
	if (g_strcmp0(word,"talk")==0) {
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "ao");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "k");     
    }
	
	if (g_strcmp0(word,"tea")==0) {
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause1");	    
    }
	
	if (g_strcmp0(word,"two")==0) {
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "uw");
	phone_list = g_list_append(phone_list, "pause1");   
    }
	
	if (g_strcmp0(word,"three")==0) {
	phone_list = g_list_append(phone_list, "th");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause1");	     
    }
	
	if (g_strcmp0(word,"ten")==0) {
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");	     
    }
	
	if (g_strcmp0(word,"twelve")==0) {
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "w");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "v"); 	     
    }
	
	if (g_strcmp0(word,"thirteen")==0) {
	phone_list = g_list_append(phone_list, "th");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");     
    }
	
	if (g_strcmp0(word,"third")==0) {
	phone_list = g_list_append(phone_list, "th");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "d");	     
    }
    
	if (g_strcmp0(word,"tenth")==0) {
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "th");	     
    }	
	
	if (g_strcmp0(word,"twelvth")==0) {
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "w");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "v"); 
	phone_list = g_list_append(phone_list, "th"); 	     
    }	
	
	if (g_strcmp0(word,"thirteenth")==0) {
	phone_list = g_list_append(phone_list, "th");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "th"); 	     
    }
      
    if (g_strcmp0(word,"twentieth")==0) {
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "w");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "t"); 
	phone_list = g_list_append(phone_list, "iy"); 
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "ah"); 
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "th"); 	    
    }
	
	if (g_strcmp0(word,"twenty")==0) {
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "w");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "t"); 
	phone_list = g_list_append(phone_list, "iy"); 
	phone_list = g_list_append(phone_list, "pause0");	    
    }
	
	if (g_strcmp0(word,"thirty")==0) {
	phone_list = g_list_append(phone_list, "th");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "d");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause0");	    
    }
	
	if (g_strcmp0(word,"thirtieth")==0) {
	phone_list = g_list_append(phone_list, "th");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "th"); 	    
    }
		
	if (g_strcmp0(word,"tuesday")==0) {
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "y");			
	phone_list = g_list_append(phone_list, "uw");	
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "z");	; 	
	phone_list = g_list_append(phone_list, "d");
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause2"); 	     
    }
    
	if (g_strcmp0(word,"thursday")==0) {
	phone_list = g_list_append(phone_list, "th");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "z");
	phone_list = g_list_append(phone_list, "d");
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause2"); 	   
    }
		
	if (g_strcmp0(word,"today")==0) {
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "uw");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "d");
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause1");    
    }
   
    if (g_strcmp0(word,"to")==0) {
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause1");
    }
  
	if (g_strcmp0(word,"tax")==0) {
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "ae");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "s");	   
    }
	
	if (g_strcmp0(word,"theatre")==0) {
	phone_list = g_list_append(phone_list, "th");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause0"); 	     
    }
	
	if (g_strcmp0(word,"train")==0) {
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");	    
    }
   
    if (g_strcmp0(word,"training")==0) {
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "ng");		    
    }
  
	if (g_strcmp0(word,"travel")==0) {
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "ae");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "v");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "l"); 	     
    }
	
	if (g_strcmp0(word,"television")==0) {
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "v"); 
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0"); 
	phone_list = g_list_append(phone_list, "zh"); 
	phone_list = g_list_append(phone_list, "ah"); 
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "n");     
    }
	
	
	//------------------------------------------------------------------
	//U words
	//------------------------------------------------------------------
	
	if (g_strcmp0(word,"update")==0) {
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "p");
	phone_list = g_list_append(phone_list, "d");	
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause2");
	phone_list = g_list_append(phone_list, "t"); 	    
    }
	
	
	//------------------------------------------------------------------
	//V words
	//------------------------------------------------------------------
	if (g_strcmp0(word,"vacation")==0) {
	phone_list = g_list_append(phone_list, "v");
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "sh"); 
	phone_list = g_list_append(phone_list, "ah"); 
	phone_list = g_list_append(phone_list, "pause0");	
	phone_list = g_list_append(phone_list, "n");     
    }

	if (g_strcmp0(word,"vehicle")==0) {
	phone_list = g_list_append(phone_list, "v");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "hh");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "k"); 
	phone_list = g_list_append(phone_list, "ah"); 
	phone_list = g_list_append(phone_list, "pause0");	
	phone_list = g_list_append(phone_list, "l");     
    }
	
	if (g_strcmp0(word,"valentine")==0) {
	phone_list = g_list_append(phone_list, "v");
	phone_list = g_list_append(phone_list, "ae");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "t"); 
	phone_list = g_list_append(phone_list, "ay");
	phone_list = g_list_append(phone_list, "pause2"); 
	phone_list = g_list_append(phone_list, "n");     
    }
	
	if (g_strcmp0(word,"valentines")==0) {
	phone_list = g_list_append(phone_list, "v");
	phone_list = g_list_append(phone_list, "ae");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "t"); 
	phone_list = g_list_append(phone_list, "ay");
	phone_list = g_list_append(phone_list, "pause2"); 
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "z");     
    }
	
	if (g_strcmp0(word,"visit")==0) {
	phone_list = g_list_append(phone_list, "v");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "z");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "t");      
    }
	
	if (g_strcmp0(word,"version")==0) {
	phone_list = g_list_append(phone_list, "v");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "zh");
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "n");
	       
    }
	
	//------------------------------------------------------------------
	//W words
	//------------------------------------------------------------------

	if (g_strcmp0(word,"world")==0) {
	phone_list = g_list_append(phone_list, "w");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause2");
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "d");  
    }
    
    if (g_strcmp0(word,"word")==0) {
	phone_list = g_list_append(phone_list, "w");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause1");	
	phone_list = g_list_append(phone_list, "d");  
    }
        
    if (g_strcmp0(word,"wind")==0) {
	phone_list = g_list_append(phone_list, "w");
	phone_list = g_list_append(phone_list, "ay");
	phone_list = g_list_append(phone_list, "pause1");	
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "d");  
    }
	
	if (g_strcmp0(word,"wednesday")==0) {
	phone_list = g_list_append(phone_list, "w");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n");
	phone_list = g_list_append(phone_list, "z");
	phone_list = g_list_append(phone_list, "d"); 
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause0"); 	     
    }
	
	if (g_strcmp0(word,"walk")==0) {
	phone_list = g_list_append(phone_list, "w");
	phone_list = g_list_append(phone_list, "ao");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "k");	    
    }
	
	if (g_strcmp0(word,"wedding")==0) {
	phone_list = g_list_append(phone_list, "w");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "d");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "ng"); 	     
    }
	
	if (g_strcmp0(word,"work")==0) {
	phone_list = g_list_append(phone_list, "w");
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "k");	     
    }
	
	
	if (g_strcmp0(word,"week")==0) {
	phone_list = g_list_append(phone_list, "w");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "k");	     
    }
		
	if (g_strcmp0(word,"weekday")==0) {
	phone_list = g_list_append(phone_list, "w");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "d");
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause2"); 	    
    }
	
    
	if (g_strcmp0(word,"weekend")==0) {
	phone_list = g_list_append(phone_list, "w");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause2");
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "d"); 	     
    }
		
	
	//------------------------------------------------------------------
	//X words
	//------------------------------------------------------------------
	
	//------------------------------------------------------------------
	//Y words
	//------------------------------------------------------------------
	
	if (g_strcmp0(word,"you")==0) {
	phone_list = g_list_append(phone_list, "y");
	phone_list = g_list_append(phone_list, "uw");
	phone_list = g_list_append(phone_list, "pause1");
     }
	
	//------------------------------------------------------------------
	//z words
	//------------------------------------------------------------------
	
	if (g_strcmp0(word,"zero")==0) {
	phone_list = g_list_append(phone_list, "z");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "ow");
	phone_list = g_list_append(phone_list, "pause0");	    
    }
	   
	
	return phone_list;
}	

