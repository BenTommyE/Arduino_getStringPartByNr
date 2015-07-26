String ipAdress = "192.168.10.145";

void setup() {
  Serial.begin(9600); //debug port
  
  Serial.println("Start");
  Serial.println();
  
  
  //Example 
  Serial.print("0: ");
  Serial.println(getStringPartByNr(ipAdress, '.', 0));  // the first part - return "192"
  
  Serial.print("1: ");
  Serial.println(getStringPartByNr(ipAdress, '.', 1));  // the 2. part - return "168"
  
  Serial.print("2: ");
  Serial.println(getStringPartByNr(ipAdress, '.', 2));  // the 3. part - return "10"
  
  Serial.print("3: ");
  Serial.println(getStringPartByNr(ipAdress, '.', 3));  // the 4. part - return "145"
  
  Serial.print("4: ");
  Serial.println(getStringPartByNr(ipAdress, '.', 4));  // this part do not exist and return ""
  
}

void loop() {
  
}

String getStringPartByNr(String data, char separator, int index)
{
    // spliting a string and return the part nr index
    // split by separator
    
    int stringData = 0;        //variable to count data part nr 
    String dataPart = "";      //variable to hole the return text
    
    for(int i = 0; i<data.length(); i++) {    //Walk through the text one letter at a time
      
      if(data[i]==separator) {
        //Count the number of times separator character appears in the text
        stringData++;
        
      }else if(stringData==index) {
        //get the text when separator is the rignt one
        dataPart.concat(data[i]);
        
      }else if(stringData>index) {
        //return text and stop if the next separator appears - to save CPU-time
        return dataPart;
        break;
        
      }

    }
    //return text if this is the last part
    return dataPart;
}
