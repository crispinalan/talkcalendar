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
	
	if (g_strcmp0(word,"builder")==0) {
	phone_list = g_list_append(phone_list, "b");
	phone_list = g_list_append(phone_list, "ih");
	phone_list = g_list_append(phone_list, "pause1");	
	phone_list = g_list_append(phone_list, "l");
	phone_list = g_list_append(phone_list, "d");  
	phone_list = g_list_append(phone_list, "er");
	phone_list = g_list_append(phone_list, "pause0");     
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
	
	//------------------------------------------------------------------
	//C words
	//------------------------------------------------------------------
		
	if (g_strcmp0(word,"car")==0) {
	phone_list = g_list_append(phone_list, "k");
	phone_list = g_list_append(phone_list, "aa");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "r");	
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
		
	//------------------------------------------------------------------
	//H words
	//------------------------------------------------------------------
		
	if (g_strcmp0(word,"have")==0) {
	phone_list = g_list_append(phone_list, "hh");
	phone_list = g_list_append(phone_list, "ae");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "v");	   
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
	
	//------------------------------------------------------------------
	//L words
	//------------------------------------------------------------------
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
   
    if (g_strcmp0(word,"memo")==0) {
	phone_list = g_list_append(phone_list, "m");
	phone_list = g_list_append(phone_list, "eh");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "m");
	phone_list = g_list_append(phone_list, "ow");	
	phone_list = g_list_append(phone_list, "pause2"); 	   
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
		
	//------------------------------------------------------------------
	//N words
	//------------------------------------------------------------------
		
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
	phone_list = g_list_append(phone_list, "pause1");  
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
	
	//------------------------------------------------------------------
	//Q Words
	//------------------------------------------------------------------
	
	//------------------------------------------------------------------
	//R words
	//------------------------------------------------------------------
	
	if (g_strcmp0(word,"reminder")==0) {
	phone_list = g_list_append(phone_list, "r");
	phone_list = g_list_append(phone_list, "iy");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "m");
	phone_list = g_list_append(phone_list, "ay");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "n"); 
	phone_list = g_list_append(phone_list, "d"); 
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
	
	//------------------------------------------------------------------
	//T words
	//------------------------------------------------------------------
		
	if (g_strcmp0(word,"talk")==0) {
	phone_list = g_list_append(phone_list, "t");
	phone_list = g_list_append(phone_list, "ao");
	phone_list = g_list_append(phone_list, "pause1");
	phone_list = g_list_append(phone_list, "k");     
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
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "z");	; 	
	phone_list = g_list_append(phone_list, "d");
	phone_list = g_list_append(phone_list, "ey");
	phone_list = g_list_append(phone_list, "pause1"); 	     
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
	phone_list = g_list_append(phone_list, "ah");
	phone_list = g_list_append(phone_list, "pause0");
	phone_list = g_list_append(phone_list, "d");
	phone_list = g_list_append(phone_list, "ey");
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

