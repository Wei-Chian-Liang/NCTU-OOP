#include "include.h"
#include "page_base.h"
#include "throw_coin.h"
#include "player.h"
#include "Tool.h"

const int total_type = 4;
string type[total_type] = {"background_", "word_", "character_", "tool_"};
int front_pagenum[total_type+1] = {1, 9, 0, 0, 0};//backgroundnum, wordnnum, characternum, toolnum, start
int rule1_pagenum[total_type+1] = {0, 2, 0, 0, 100};
int rule2_pagenum[total_type+1] = {0, 2, 0, 0, 102};
int character_intro1_pagenum[total_type+1] = {0, 2, 0, 0, 200};
int character_intro2_pagenum[total_type+1] = {0, 2, 0, 0, 202};
int tool_intro_pagenum[total_type+1] = {0, 2, 0, 0, 300};
int choose_chara_pagenum[total_type+1] = {2, 0, 0, 0, 400};
int fight_pagenum[total_type+1] = {2, 0, 0, 2, 500};


void show_page(struct page_base &, int *);
void get_tool(Player &, picture &tool);

int main( int argc, char* args[] )
{
  SDL_Init(SDL_INIT_EVERYTHING);
 
  //Set OpenGL memory usage
  SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
  SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8);
  SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );
  SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8);
  SDL_GL_SetAttribute( SDL_GL_BUFFER_SIZE, 32);
  SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
  SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
 
  //Caption of the window
  SDL_WM_SetCaption( "New-War of cat and dog", NULL );

  SDL_Surface *screen;

  //Size of the window
  screen = SDL_SetVideoMode(600,400,32, SDL_OPENGL );
 
  //Specific the clear color
  glClearColor(1,1,1,1); //RED,GREEN,BLUE,ALPHA
 
  //What portion of the screen we will display
  glViewport(0,0,600,400);
 
  //Shader model - Use this
  glShadeModel(GL_SMOOTH);
 
  //2D rendering
  glMatrixMode(GL_PROJECTION);

  //"Save" it
  glLoadIdentity();
 
  //Disable depth checking
  glDisable(GL_DEPTH_TEST);
 
  //We enable blending of textures and set how we are going to blend it
  glEnable( GL_BLEND );
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
 
  //Handles the main loop
  bool isRunning = true;
 
  //For handling with event
  SDL_Event event;

  bool left = false, right = false, a=false, s=false, d=false, k=false, x=false, c=false; //we save in which state the button is  

  bool front_flag = true, rule1_flag = false, rule2_flag = false, character_intro1_flag = false, character_intro2_flag = false, tool_intro_flag = false;

  bool start_game = false, choose_chara = false, coin = false, fight = false;

  bool blue_flag = false, red_flag=false, run_flag = false, move_flag = true, bullet_flag = false, use_tool_flag = false;

  //create front_page
  struct page_base front_page(front_pagenum);
  struct page_base rule1_page(rule1_pagenum);
  struct page_base rule2_page(rule2_pagenum);
  struct page_base character_intro1_page(character_intro1_pagenum);
  struct page_base character_intro2_page(character_intro2_pagenum);
  struct page_base tool_intro_page(tool_intro_pagenum);
  struct page_base choose_chara_page(choose_chara_pagenum);
  struct page_base fight_page(fight_pagenum);
  
  fight_page.picture[0][1].set(275, 250, 50,150);//wall
  fight_page.picture[3][0].set(60, 10, 40, 40);//blue team tool
  fight_page.picture[3][1].set(500, 10, 40,40);//red team tool

  Player blue(30, 330);
  Player red(500, 330);

  int count=0;//for judge run;
  int choose_tool;

  
  struct picture tool[3];
  tool[0].stored=Loadpicture("tool_", "10");
  tool[0].set(0,0,50,50);
  tool[1].stored=Loadpicture("tool_", "11");
  tool[1].set(0,0,50,50);
  tool[2].stored=Loadpicture("tool_", "12");
  tool[2].set(0,0,50,50);

  //Main game loop
  while ( isRunning )
    {
      //EVENTS
      while ( SDL_PollEvent(&event) )
        {
          //if the window was closed
          if ( event.type == SDL_QUIT )
            {
              isRunning = false;
            }
 
          //If a button was released and the button is escape
          if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE )
            {
              isRunning = false;
            }
 
          if ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_r )
            {
              glClearColor(1,0,0,1);
            }
 
          if ( event.type == SDL_KEYDOWN ) //Check for presed down buttons
            {
              if ( event.key.keysym.sym == SDLK_LEFT ) //Check left key
                  left = true; //Set the boolean value for left key to true (it is pressed) 
              else if ( event.key.keysym.sym == SDLK_RIGHT ) //Check Right key
                  right = true; //Set the boolean value for right key to true (it is pressed)
			  else if ( event.key.keysym.sym == SDLK_a )
                  a = true;
			  else if ( event.key.keysym.sym == SDLK_s )
                  s = true;
			  else if ( event.key.keysym.sym == SDLK_d )
                  d = true;
			  else if ( event.key.keysym.sym == SDLK_k )
                  k = true;
			  else if ( event.key.keysym.sym == SDLK_x )
                  x = true;
			  else if ( event.key.keysym.sym == SDLK_c )
                  c = true;
            }
 
          else if ( event.type == SDL_KEYUP ) //Checking for released buttons
            {
              if ( event.key.keysym.sym == SDLK_LEFT ) //Left key
                  left = false; //Set the value to false (key is released)
              else if ( event.key.keysym.sym == SDLK_RIGHT ) //Right key
                  right = false; //Key is released
			  else if ( event.key.keysym.sym == SDLK_a )
                  a = false;
			  else if ( event.key.keysym.sym == SDLK_s )
                  s = false;
			  else if ( event.key.keysym.sym == SDLK_d )
                  d = false;
			  else if ( event.key.keysym.sym == SDLK_k )
                  k = false;
			  else if ( event.key.keysym.sym == SDLK_x )
                  x = false;
			  else if ( event.key.keysym.sym == SDLK_c )
                  c = false;
            }
          //logic that should happen for a certain event
        }
   
	  //LOGIC
	  if (front_flag == true){
	    if ( a == true && front_page.picture[1][2].exist == true) //If 'a' key is pressed
		    front_page.picture[1][2].exist = false;//show bottom pressed
		else if ( s == true && front_page.picture[1][4].exist == true) //If 's' key is realsed and have showen bottom pressed
		    front_page.picture[1][4].exist = false; //show bottom pressed
		else if ( d == true && front_page.picture[1][6].exist == true) //If 'd' key is realsed and have showen bottom pressed
			front_page.picture[1][6].exist = false; //show bottom pressed
	    else if ( k == true && front_page.picture[1][8].exist == true) //If 'k' key is realsed and have showen bottom pressed
			front_page.picture[1][8].exist = false; //show bottom pressed
	  }
	  else if (rule1_flag == true){
		if ( x == true && rule1_page.picture[1][1].exist == true) //If 'x' key is pressed
		    rule1_page.picture[1][1].exist = false;//show bottom pressed
	  }
	  else if (rule2_flag == true){
		if ( c == true && rule2_page.picture[1][1].exist == true) //If 'c' key is pressed
		    rule2_page.picture[1][1].exist = false;//show bottom pressed
	  }
	  else if (character_intro1_flag == true){
		if ( x == true && character_intro1_page.picture[1][1].exist == true) //If 'x' key is pressed
		    character_intro1_page.picture[1][1].exist = false;//show bottom pressed
	  }
	  else if (character_intro2_flag == true){
		if ( c == true && character_intro2_page.picture[1][1].exist == true) //If 'c' key is pressed
		    character_intro2_page.picture[1][1].exist = false;//show bottom pressed
	  }
	  else if (tool_intro_flag == true){
		if ( c == true && tool_intro_page.picture[1][1].exist == true) //If 'c' key is pressed
		    tool_intro_page.picture[1][1].exist = false;//show bottom pressed
	  }
	  else if (choose_chara == true && blue_flag == true && red_flag != true){ //judge blue's caracter
			if (a == true){
			  blue.set_charac_type(0);
			  red_flag = true;
			}
			else if (s == true){
			  blue.set_charac_type(1);
			  red_flag = true;
			}
			else if (d == true){
			  blue.set_charac_type(2);
			  red_flag = true;
			}
			SDL_Delay(100);
	  }
	  else if (choose_chara == true && red_flag == true){ //judge red's caracter
			if (a == true){
			  red.set_charac_type(0);
			  blue_flag = false;
			}
			else if (s == true){
			  red.set_charac_type(1);
			  blue_flag = false;
			}
			else if (d == true){
			  red.set_charac_type(2);
			  blue_flag = false;
			}
	  }
	  else if (fight == true && move_flag == true && blue_flag == true && count%3==1){
		if (a == true){
		  if (blue.playerpic.x - 5 < 30)
			blue.playerpic.x = 30;
		  else
			blue.move_left();
		}
		else if (d == true){
		  if (blue.playerpic.x + 5 + blue.playerpic.width > 275)
			blue.playerpic.x = 275-blue.playerpic.width;
		  else
			blue.move_right();
		}
		else if (k == true){
		  move_flag = false;
		  count+=1;
		}
		else if (x == true){
		  use_tool_flag = true;
		  blue.tool_type = -1;
		}
	  }
	  else if (fight == true && move_flag == true && red_flag == true && count%3==1){
		if (a == true){
		  if (red.playerpic.x - 5 < 325)
			red.playerpic.x = 325;
		  else
			red.move_left();
		}
		else if (d == true){
		  if (red.playerpic.x + 5 + red.playerpic.width > 570)
			red.playerpic.x = 570-red.playerpic.width;
		  else
			red.move_right();
		}
		else if (k == true){
		  move_flag = false;
		  count+=1;
		}
		else if (x == true){
		  use_tool_flag = true;
		  red.tool_type = -1;
		}
	  }

	  if (start_game == true && coin == true){
		  if (throw_coin()==true){
			cout<<"true"<<endl;
			blue_flag = true;
			red_flag = false;
		  }
		  else{
			cout<<"false"<<endl;
			blue_flag = false;
			red_flag = true;
		  }
		  coin = false;
		  fight = true;
	  }

      //RENDERING to the screen
      glClear(GL_COLOR_BUFFER_BIT);
	  
	  glPushMatrix(); //Start rendering phase
 
	  glOrtho(0,600,400,0,-1,1); //Set the matrix

	  if (front_flag == true){
		show_page(front_page, front_pagenum);
		if (front_page.picture[1][2].exist == false){
		  front_page.picture[1][2].exist = true;
		  front_flag = false;
		  rule1_flag = true;
		}
		if (front_page.picture[1][4].exist == false){
		  front_page.picture[1][4].exist = true;
		  front_flag = false;
		  character_intro1_flag = true;
		}
		if (front_page.picture[1][6].exist == false){
		  front_page.picture[1][6].exist = true;
		  front_flag = false;
		  tool_intro_flag = true;
		}
		if (front_page.picture[1][8].exist == false){
		  front_page.picture[1][8].exist = true;
		  front_flag = false;
		  start_game = true;
		  choose_chara = true;
		}
	  }

	  else if (rule1_flag == true){
		show_page(rule1_page, rule1_pagenum);
		if (rule1_page.picture[1][1].exist == false){
		  rule1_page.picture[1][1].exist = true;
		  rule1_flag = false;
		  rule2_flag = true;
		}
	  }

	  else if (rule2_flag == true){
		show_page(rule2_page, rule2_pagenum);
		if (rule2_page.picture[1][1].exist == false){
		  rule2_page.picture[1][1].exist = true;
		  rule2_flag = false;
		  front_flag = true;
		}
	  }

	  else if (character_intro1_flag == true){
		show_page(character_intro1_page, character_intro1_pagenum);
		if (character_intro1_page.picture[1][1].exist == false){
		  character_intro1_page.picture[1][1].exist = true;
		  character_intro1_flag = false;
		  character_intro2_flag = true;
		}
	  }

	  else if (character_intro2_flag == true){
		show_page(character_intro2_page, character_intro2_pagenum);
		if (character_intro2_page.picture[1][1].exist == false){
		  character_intro2_page.picture[1][1].exist = true;
		  character_intro2_flag = false;
		  front_flag = true;
		}
	  }

	  else if (tool_intro_flag == true){
		show_page(tool_intro_page, tool_intro_pagenum);
		if (tool_intro_page.picture[1][1].exist == false){
		  tool_intro_page.picture[1][1].exist = true;
		  tool_intro_flag = false;
		  front_flag = true;
		}
	  }

	  else if (start_game == true){
		if (choose_chara == true){
		  if (blue_flag != true && red_flag == true){
			choose_chara = false;
			coin = true;
		  }
		  else if (red_flag != true){
			show_page(choose_chara_page, choose_chara_pagenum);//for choose blue chara
			blue_flag = true;
		  }
		  else if (blue_flag == true && red_flag == true){
			choose_chara_page.picture[0][1].exist = false;
			show_page(choose_chara_page, choose_chara_pagenum);//for choose red chara
		  }
		}
		

		else if (fight == true){
		  show_page(fight_page, fight_pagenum);//show background and wall
		  showpicture(blue.playerpic);//show blue player
		  showpicture(red.playerpic);//show red player
		  if (blue.tool_type != -1){//show blue tool
			blue.tool.set(62, 12, 36, 36);
			showpicture(blue.tool);
		  }
		  if (red.tool_type != -1){//show red tool
			red.tool.set(502, 12, 36, 36);
			showpicture(red.tool);
		  }
		  if (count%3 == 0){
			srand(time(NULL));
			choose_tool=rand()%3;
			tool[choose_tool].x=150+rand()%300;
			tool[choose_tool].y=100+rand()%100-50;
			count++;
		  }
		  showpicture(tool[choose_tool]);
		  if (blue_flag == true && count%3 == 2){
			if (move_flag == false)
			  if (use_tool_flag == true){
				if (blue.tool_type == 0)
				  Tool_IncreaseHp(blue);
				else if (blue.tool_type == 1)
				  Tool_IncreaseHit(blue);
				else if (blue.tool_type == 2)
				  Tool_Aim(blue, red);
				use_tool_flag = false;
			  }
			  blue.attack(10,1);
			  blue.weapon.picture[0].x=blue.playerpic.x;
			  blue.weapon.picture[0].y=blue.playerpic.y;
			  while(1){
				show_page(fight_page, fight_pagenum);//show background and wall
				showpicture(blue.playerpic);//show blue player
				showpicture(red.playerpic);//show red player
				if (blue.tool_type != -1){//show blue tool
				  blue.tool.set(62, 12, 36, 36);
				  showpicture(blue.tool);
				}
				if (red.tool_type != -1){//show red tool
				  red.tool.set(502, 12, 36, 36);
				  showpicture(red.tool);
				}
				showpicture(tool[choose_tool]);
				blue.weapon.picture[0].vy-=5;
				showpicture(blue.weapon.picture[0]);
				get_tool(blue, tool[choose_tool]);
				cout<<"fb"<<endl;
				cout<<blue.playerpic.x<<endl;
				if (blue.weapon.picture[0].y > 530){
				  //bullet_flag = false;
				  count++;
				  blue_flag = false;
				  red_flag = true;
				  move_flag = true;
				  cout<<"stop b"<<endl;
				  break;
				}
				else if (blue.weapon.picture[0].y+blue.weapon.picture[0].height > 250 && blue.weapon.picture[0].x<325 && blue.weapon.picture[0].x+blue.weapon.picture[0].width>275){
				  //bullet_flag = false;
				  count++;
				  blue_flag = false;
				  red_flag = true;
				  move_flag = true;
				  cout<<"stop b"<<endl;
				  break;
				}
				SDL_GL_SwapBuffers();
				SDL_Delay(50);
			  }
			  //bullet_flag = true;
		  }
		  else if (red_flag == true && count%3 == 2){
			if (move_flag == false)
			  if (use_tool_flag == true){
				if (red.tool_type == 0)
				  Tool_IncreaseHp(blue);
				else if (red.tool_type == 1)
				  Tool_IncreaseHit(blue);
				else if (red.tool_type == 2)
				  Tool_Aim(red, blue);
				use_tool_flag = false;
			  }
			  red.attack(390,2);
			  red.weapon.picture[0].x=red.playerpic.x;
			  red.weapon.picture[0].y=red.playerpic.y;
			  while(1){
				show_page(fight_page, fight_pagenum);//show background and wall
				showpicture(blue.playerpic);//show blue player
				showpicture(red.playerpic);//show red player
				if (blue.tool_type != -1){//show blue tool
				  blue.tool.set(62, 12, 36, 36);
				  showpicture(blue.tool);
				}
				if (red.tool_type != -1){//show red tool
				  red.tool.set(502, 12, 36, 36);
				  showpicture(red.tool);
				}
				showpicture(tool[choose_tool]);
				red.weapon.picture[0].vy-=5;
				showpicture(red.weapon.picture[0]);
				get_tool(red, tool[choose_tool]);
				cout<<"fr"<<endl;
				if (red.weapon.picture[0].y > 530){
				  bullet_flag = false;
				  count++;
				  //blue_flag = false;
				  blue_flag = true;
				  red_flag = false;
				  move_flag = true;
				  cout<<"stop r"<<endl;
				  break;
				}
				else if (red.weapon.picture[0].y+red.weapon.picture[0].height > 250 && red.weapon.picture[0].x<325 && red.weapon.picture[0].x+red.weapon.picture[0].width>275){
				  bullet_flag = false;
				  count++;
				  //blue_flag = false;
				  blue_flag = true;
				  red_flag = false;
				  move_flag = true;
				  cout<<"stop r"<<endl;
				  break;
				}
				SDL_GL_SwapBuffers();
				SDL_Delay(50);
			  }
			  //bullet_flag = true;
		  }
		}

	  }

	  glPopMatrix(); //End rendering phase
 
	  SDL_GL_SwapBuffers();

      SDL_Delay(50); //Delay / pause
    }
 
  SDL_Quit();
 
  return 0;
}

void show_page(struct page_base &b, int *total){
  for (int i=0; i<total_type; i++)
	for (int j=0; j<total[i]; j++)
	  b.show(type[i], j);
}

void get_tool(Player &p, picture &tool){
  for (int i=0; i<3; i++){
	if (p.weapon.picture[0].y+(p.weapon.picture[0].height/2) > tool.y && p.weapon.picture[0].y+(p.weapon.picture[0].height/2) < tool.y+tool.height && p.weapon.picture[0].x+(p.weapon.picture[0].width/2) > tool.x && p.weapon.picture[0].x+(p.weapon.picture[0].width/2) < tool.x+tool.width){
	  p.tool = tool;
	  p.tool_type = i;
	}
	else if (p.weapon.picture[2].y+(p.weapon.picture[2].height/2) > tool.y && p.weapon.picture[2].y+(p.weapon.picture[2].height/2) < tool.y+tool.height && p.weapon.picture[2].x+(p.weapon.picture[2].width/2) > tool.x && p.weapon.picture[2].x+(p.weapon.picture[2].width/2) < tool.x+tool.width){
	  p.tool = tool;
	  p.tool_type = i;
	}
  }
}