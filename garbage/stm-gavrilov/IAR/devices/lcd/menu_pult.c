
/* Позиция в меню 
int menu_position;

switch ( menu_position ) {
    case MAIN_MENU:  
      switch (event) {
        case BUTTON_1 :  
          main_menu_draw();			
          break;
        case BUTTON_2 :  
          main_menu_draw_number();			
          break;	
        case 3 :  
          main_menu_draw_number();			
          break;			
        default: 
          break;		 
      }
      break;
    case 1_MENU :  
      switch (event) {
        case BUTTON_1 :  
          main_menu_draw();			
          break;
        case BUTTON_2 :  
          main_menu_draw_number();			
          break;	
        case 3 :  
          main_menu_draw_number();			
          break;			
        default: 
          break;		 
      }
      break;            
    case 2_MENU :  
      switch (event){
        case BUTTON_1 :  
          main_menu_draw();			
          break;
        case BUTTON_2 :  
          main_menu_draw_number();			
          break;	
        case 3 :  
          main_menu_draw_number();			
          break;			
        default: 
          break;		 
		}	
      break;
    case 3_MENU :  {
		switch (event){
			case BUTTON_1 :  {
			main_menu_draw();			
			}		 break;
			case BUTTON_2 :  {
			main_menu_draw_number();			
			}		 break;	
			case 3 :  {
			main_menu_draw_number();			
			}		 break;			
			default: break;		 
		}	
	}break;
    case 4_MENU :  {
		switch (event){
			case BUTTON_1 :  {
				switch (previous_menu_position){
					case BUTTON_1 :  {
					main_menu_draw();			
					}		 break;
					case BUTTON_2 :  {
					main_menu_draw_number();			
					}		 break;	
					case 3 :  {
					main_menu_draw_number();			
					}		 break;			
					default: break;				
				}		 break;
			case BUTTON_2 :  {
			main_menu_draw_number();			
			}		 break;	
			case 3 :  {
			main_menu_draw_number();			
			}		 break;			
			default: break;		 
		}	
	}break;	
	default:      return ERROR;
             break;		 
}

//Итого структура 
typedef struct menu_pult_state_s {
  unsigned char   event;                    //необходима очередь и приоритет(но не в этот раз:) )
  unsigned char   menu_position;
  unsigned char   previous_menu_position;   //для повторного использования одного меню(например стандартное подтверждение)
} menu_pult_state_t;

event - для кнопки и еще какието эвенты
*/