//___________________________________________________ my usual setting
const boolean dbp=true;        // false                 // false  here can disable diagnostic printout 
#define db(t,x)     if(t) { Serial.print(x); }
#define dbln(t,x)   if(t) { Serial.println(x); }
                                                        // use: 
                                                        // dbln(dbp,"test");

//___________________________________________________ GLOBAL VARS
float voltage = 0.00;
float ampere = 0.00;

//___________________________________________________ SETUP
void setup() {
    Serial.begin(115200);
    while (!Serial){
    ;                                                 // needed for leonardo
    }
    print_in_setup();
    
}

//___________________________________________________ LOOP
void loop() {
    refreshReadings();
    delay(5000);
}
