
package T1aJavaF10;


public class Manager extends Staff  {

    private StaffApointHandler staffApoint;

    public Manager() {
        this("","", 0.0);
    }

    public Manager(String workAtStr, String nameStr, double salaryD) {
        super(workAtStr, nameStr, salaryD);
    }

     public Manager(Manager man) {
        this(man.getWorkAt(), man.getName(), man.getSalary());
    }


     public void addStaffApointListener(StaffApointHandler staffA){

         this.staffApoint = staffA;
         
     }

     public void onStaffApoint(Staff member, double newStaffMemberSalary){
         if(staffApoint != null){

         staffApoint.addStaff(new StaffAppointEventArgs(member, newStaffMemberSalary));
         
         }
     }

    public String toString(){

        return super.toString();
    }
    

}
