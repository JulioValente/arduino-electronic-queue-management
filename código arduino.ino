#include <LiquidCrystal.h>
#include <stdio.h>

//botões
#define RetiraSenha 6
#define ChamaSenha 7

int senhaAtual=0;
int senhaFinal=0;

//configura o display
LiquidCrystal lcd(0, 1, 2, 3, 4, 5);

void setup(){
  //configura os botões
  pinMode(RetiraSenha, INPUT_PULLUP);
  pinMode(ChamaSenha, INPUT_PULLUP);
  
  //inicia o display
  lcd.begin(16, 2);
  lcd.noCursor();
  lcd.noBlink();  
}

void loop(){    
  if(!digitalRead(RetiraSenha)){ //retira uma senha
    senhaFinal++;
    lcd.print("Sua senha:");
    
    //escreve a senha retirada
    lcd.setCursor(0, 1);
    char num[4];
    sprintf(num, "%.3d", senhaFinal); //formata uma string para imprimir a senha
    lcd.print(num);
    
    //espera para limpar o display
    delay(2000);
    lcd.clear();
  }else if(!digitalRead(ChamaSenha)){ //chama a senha atual 
    if(senhaAtual >= senhaFinal){ //se não tiver ninguém na fila
      lcd.print("Ninguem na fila");
      
      //espera para limpar o display
      delay(2000);
      lcd.clear();
    }else{            
      senhaAtual++;
      lcd.print("Chamando senha:");      
      
      //escreve a senha chamada
      lcd.setCursor(0, 1);    
      char num[4];
      sprintf(num, "%.3d", senhaAtual); //formata uma string para imprimir a senha
      lcd.print(num);
      
      //espera para limpar o display
      delay(2000);
      lcd.clear();
    }
  }    
}