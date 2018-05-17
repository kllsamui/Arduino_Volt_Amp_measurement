//___________________________________________________ measuring board voltage divider
float Av = 0.0;
float Bv =0.0244;
//___________________________________________________ measuring board ACS712 HALL
float Aoff= 512.0;                                    // MOD KLL for HALL
float Ai = 0.10;                                      // MOD KLL after 5V/12.8A test
float Bi = 0.0750;                                    // MOD KLL after 5V/12.8A test

//___________________________________________________ show params at boot
void print_in_setup(){
  dbln(dbp,"Parameter Setup");
  dbln(dbp,"VFinal = Av + Bv * VRaw(A0)");
  db(dbp,"Av =: "); dbln(dbp,Av);
  db(dbp,"Bv =: "); if (dbp) { Serial.println(Bv,4); }
  
  dbln(dbp,"IFinal = Ai + Bi * ( IRaw(A1)- Aoff )");
  db(dbp,"Ai =: "); dbln(dbp,Ai);
  db(dbp,"Bi =: "); if (dbp) { Serial.println(Bi,4); }
  db(dbp,"Aoff =: "); dbln(dbp,Aoff);
 
    }

//___________________________________________________ read analog A0 VOLT ( via voltage divider )
float getV() {
  float VRaw = analogRead(A0);
  float VFinal = Av + Bv * VRaw;
  db(dbp," // VRaw: "); db(dbp,VRaw); db(dbp,", VFinal: "); db(dbp,VFinal);
  return VFinal;
}

//___________________________________________________ read analog A1 AMP ( via ACS712 HALL )
float getI() {
  float IRaw = analogRead(A1);
  float IFinal = Ai + Bi * (IRaw - Aoff);               // MOD KLL for HALL
  db(dbp," // IRaw: "); db(dbp,IRaw); db(dbp,", IFinal: "); dbln(dbp,IFinal);
  return IFinal;
}

//___________________________________________________ get measurements TO GLOBAL VARS
void refreshReadings() {
  db(dbp,"time: "); db(dbp,millis()/1000);
  voltage = getV();
  ampere  = getI();
}

