

package T1aJavaF10;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.logging.Level;
import java.util.logging.Logger;


public class HRdepartment implements Serializable {

    private Manager manager;
    private Staff[] staff;
   

    public HRdepartment(Manager man) {
        setManager(man);
        staff = new Staff[15];
    }

    public void setManager(Manager man) {
        if(man == null){
            this.manager = new Manager();
        }else{
            this.manager = new Manager(man);
        }
    }

    public void setStaff(Staff[] staffArray) {
        if(staffArray == null){
            this.staff = new Staff[]{};
        }else{
            for(int i =0; i < staffArray.length; i++){
            this.staff[i] = staffArray[i];
            }
        }
    }

    public Manager getManager() {
        return new Manager(manager);
    }

    public Staff[] getStaff() {
       Staff[] buffer = new Staff[staff.length];

       for(int i = 0; i < buffer.length; i++){
            buffer[i] = new Staff(staff[i]);
       }
       return buffer;
    }

    public void recordStaff(File fileName){
        
        if(fileName != null){
            
        try {
            ObjectOutputStream output = new ObjectOutputStream(new FileOutputStream(fileName));

            for(int i = 0; i < staff.length; i++){

                output.writeObject(staff[i]);
            }

            output.close();

        } catch (IOException ex) {
            Logger.getLogger(HRdepartment.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        }
        
    }

    private class InnerClass implements StaffApointHandler{
      

        private String appointDepartment;

        public InnerClass(String appoint) {
          setAppointDepartment(appoint);
        }

         public void setAppointDepartment(String appoint) {
            if(appoint == null){
                  this.appointDepartment = "";
            }else{
                  this.appointDepartment = appoint;
            }
        }

        public String getAppointDepartment() {
            return appointDepartment;
        }

        public void addStaff(StaffAppointEventArgs staffAppoint){
            if(staffAppoint != null){
            Staff staffNew = staffAppoint.getStaff();
            staffNew.setWorkAt(appointDepartment);
            double newSalary = staffAppoint.getSalary();
            staffNew.setSalary(newSalary);
            staff = new Staff[]{ new Staff(staffNew.getWorkAt(), staffNew.getName(), staffNew.getSalary())};

            // Staff chistachka = new Staff(staffNew.getWorkAt(), staffNew.getName(), staffNew.getSalary());
            //staff = new Staff[]{chistachka };
            }
        }
    }

    public StaffApointHandler getHandler(){
        //Staff chistachka = new Staff();
       // String chistachkaWorkAt = chistachka.getWorkAt();
       //  return new InnerClass(chistachkaWorkAt);
        
        // new Staff().getWorkAt()
        return new InnerClass(new Staff().getWorkAt());
    }

    public String toString(){

        StringBuilder str = new StringBuilder();

        for(int i = 0; i < staff.length; i++){

            str.append(staff[i].toString());
            
        }

        return String.format(manager.toString(), new String(str));
    }

}
