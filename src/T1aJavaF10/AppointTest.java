
package T1aJavaF10;

import java.io.File;

public class AppointTest {

    public static void main(String[] args){

        Manager boss = new Manager("Invoices", "Ivan Ivanov", 800.40);
        Staff[] candidates = new Staff[]{ new Staff("IT", "Petyr Petrov", 500.23),
        new Staff("IT", "Georgi Georgiev", 100.23)};

        System.out.println(boss);

        for(int i = 0; i < candidates.length; i++){

            System.out.println(candidates[i]);
            
        }

        HRdepartment hr = new HRdepartment(boss);
        
        boss.addStaffApointListener(hr.getHandler());

        boss.onStaffApoint(candidates[0], 1200);
        boss.onStaffApoint(candidates[1], 1800);

        hr.setStaff(candidates);

        hr.recordStaff( new File("staff.ser"));

        
    }

}
