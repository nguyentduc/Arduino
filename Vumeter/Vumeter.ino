

int music = A0;
int output,i;
int potval=A1;
int led[8] = { 2,3,4,5,8,9,10,11}; // Assign the pins for the leds
void setup()
{
for (i = 0; i < 8; i++)  
  pinMode(led[i], OUTPUT);
}

void loop()
{
potval=analogRead(A1);
output = analogRead(music);
potval=map (potval,0,1024,5,40);
output = output/potval;   

  if (output == 0) 
   {
   for(i = 0; i < 8; i++)
     {
     digitalWrite(led[i], LOW);
     }
  }
  
  else
  {
   for (i = 0; i < output; i++)
    {
     digitalWrite(led[i], HIGH);
    }
    
    for(i = i; i < 8; i++) 
     {
      digitalWrite(led[i], LOW);
    
     }
  }
}
