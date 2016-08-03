#include "data.h"
#include "string.h"
#include "menu_level1.h"
#include "LCDDefine.h"
#include "stm8s.h"
/*
 * Ñîñòîÿíèå íàñòğîåê
 */
extern CommandSettings settingsState;

/*
 * Òåêóùèé ïóíêò ìåíş
 */
extern unsigned char current_menu_item;

/*
 * Èíèöèàëèçàöèÿ ìåíş âûâîä íà ıêğàí ïåğâûå ïóíêòû ìåíş
 */
void print_level4_menu() {
  ClearDisplay();
  
  switch (current_menu_item) {
    case 1:
        if ( settingsState.stateword.a0 == 1 ) {
          OUT1( "[ÂÊË.]" );
          OUT2( "ÎÒÊË." );
        }
        else {
          OUT1( "ÂÊË." );
          OUT2( "[ÎÒÊË.]" );
        }
      break;
      
    case 2:
        if ( settingsState.stateword.a1 == 1 ) {
          OUT1( "[ÂÊË.]" );
          OUT2( "ÎÒÊË." );
        }
        else {
          OUT1( "ÂÊË." );
          OUT2( "[ÎÒÊË.]" );
        }
      break;
      
    case 3:
        if ( settingsState.stateword.a2 == 1 ) {
          OUT1( "[ÂÊË.]" );
          OUT2( "ÎÒÊË." );
        }
        else {
          OUT1( "ÂÊË." );
          OUT2( "[ÎÒÊË.]" );
        }
      break;
     
    case 4:
        if ( settingsState.stateword.a3 == 1 ) {
          OUT1( "[ÂÊË.]" );
          OUT2( "ÎÒÊË." );
        }
        else {
          OUT1( "ÂÊË." );
          OUT2( "[ÎÒÊË.]" );
        }
      break;
      
    case 5:
        if ( settingsState.stateword.a4 == 1 ) {
          OUT1( "[ÂÊË.]" );
          OUT2( "ÎÒÊË." );
        }
        else {
          OUT1( "ÂÊË." );
          OUT2( "[ÎÒÊË.]" );
        }
      break;
      
    case 6:
        if ( settingsState.stateword.a5 == 1 ) {
          OUT1( "[ÂÊË.]" );
          OUT2( "ÎÒÊË." );
        }
        else {
          OUT1( "ÂÊË." );
          OUT2( "[ÎÒÊË.]" );
        }
      break;
      
    case 7:
        if ( settingsState.stateword.a6 == 1 ) {
          OUT1( "[ÂÊË.]" );
          OUT2( "ÎÒÊË." );
        }
        else {
          OUT1( "ÂÊË." );
          OUT2( "[ÎÒÊË.]" );
        }
      break;
      
     case 8:
        if ( settingsState.stateword.a7 == 1 ) {
          OUT1( "[ÂÊË.]" );
          OUT2( "ÎÒÊË." );
        }
        else {
          OUT1( "ÂÊË." );
          OUT2( "[ÎÒÊË.]" );
        }
      break;
      
    case 9:
        if ( settingsState.stateword.a8 == 1 ) {
          OUT1( "[ÂÊË.]" );
          OUT2( "ÎÒÊË." );
        }
        else {
          OUT1( "ÂÊË." );
          OUT2( "[ÎÒÊË.]" );
        }
      break;
      
    case 10:
        if ( settingsState.stateword.a9 == 1 ) {
          OUT1( "[ÂÊË.]" );
          OUT2( "ÎÒÊË." );
        }
        else {
          OUT1( "ÂÊË." );
          OUT2( "[ÎÒÊË.]" );
        }
      break;
      
    case 11:
        if ( settingsState.stateword.a10 == 1 ) {
          OUT1( "[ÂÊË.]" );
          OUT2( "ÎÒÊË." );
        }
        else {
          OUT1( "ÂÊË." );
          OUT2( "[ÎÒÊË.]" );
        }
      break;
      
    case 12:
        if ( settingsState.stateword.a11 == 1 ) {
          OUT1( "[ÂÊË.]" );
          OUT2( "ÎÒÊË." );
        }
        else {
          OUT1( "ÂÊË." );
          OUT2( "[ÎÒÊË.]" );
        }
      break;
      
    case 13:
        if ( settingsState.stateword.a12 == 1 ) {
          OUT1( "[ÂÊË.]" );
          OUT2( "ÎÒÊË." );
        }
        else {
          OUT1( "ÂÊË." );
          OUT2( "[ÎÒÊË.]" );
        }
      break;
      
  }

}


/*
 * Âûâîä íà ıêğàí pos íîìåğ ïóíêòà ìåíş
 */
void print_level4_text_menu_by_position(unsigned char pos) {
 ClearDisplay();
  switch (pos) {
    case 1:
      OUT1( "[ÂÊË.]" );
      OUT2( "ÎÒÊË." );
      
      
        switch (current_menu_item) {
          case 1:
            settingsState.stateword.a0 = 1;
            break;
      
           case 2:
             settingsState.stateword.a1 = 1;
             break;
          
           case 3:
             settingsState.stateword.a2 = 1;
             break;
         
           case 4:
             settingsState.stateword.a3 = 1;
             break;
          
           case 5:
              settingsState.stateword.a4 = 1;
              break;
          
           case 6:
             settingsState.stateword.a5 = 1;
             break;
          
           case 7:
             settingsState.stateword.a6 = 1;
             break;
          
           case 8:
            settingsState.stateword.a7 = 1;
            break;
          
           case 9:
            settingsState.stateword.a8 = 1;
            break;
          
           case 10:
             settingsState.stateword.a9 = 1;
             break;
          
           case 11:
             settingsState.stateword.a10 = 1;
             break;
          
           case 12:
            settingsState.stateword.a11 = 1;
            break;
          
           case 13:
             settingsState.stateword.a12 = 1;
             break;
         }
     
      break;
    case 2:
      OUT1( "ÂÊË." );
      OUT2( "[ÎÒÊË.]" );
      
        switch (current_menu_item) {
          case 1:
            settingsState.stateword.a0 = 0;
            break;
      
           case 2:
             settingsState.stateword.a1 = 0;
             break;
          
           case 3:
             settingsState.stateword.a2 = 0;
             break;
         
           case 4:
             settingsState.stateword.a3 = 0;
             break;
          
           case 5:
              settingsState.stateword.a4 = 0;
              break;
          
           case 6:
             settingsState.stateword.a5 = 0;
             break;
          
           case 7:
             settingsState.stateword.a6 = 0;
             break;
          
           case 8:
            settingsState.stateword.a7 = 0;
            break;
          
           case 9:
            settingsState.stateword.a8 = 0;
            break;
          
           case 10:
             settingsState.stateword.a9 = 0;
             break;
          
           case 11:
             settingsState.stateword.a10 = 0;
             break;
          
           case 12:
            settingsState.stateword.a11 = 0;
            break;
          
           case 13:
             settingsState.stateword.a12 = 0;
             break;
         }
      
      break;
  }
}