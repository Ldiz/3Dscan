use <MCAD/involute_gears.scad>
include <MCAD/motors.scad>
use <MCAD/bearing.scad>
use <MCAD/screw.scad>
include <BOLTS.scad>


module nutWasherM8 () {
	translate([0., 0.,8-1.2])
		union() {
			ISO4032("M8", part_mode="default");
			ISO7089("M8", part_mode="default");
		}
}
//nutWasherM8();

module washerNutM8 () {
	translate([0., 0.,1.6]) 
		rotate([180., 0, 0]) 
			union() {
				ISO4032("M8", part_mode="default");
				ISO7089("M8", part_mode="default");
			}
}
// washerNutM8();

module nutWasherM3 () {
	translate([0., 0.,-0.5])
		union() {
			ISO4032("M3", part_mode="default");
			ISO7089("M3", part_mode="default");
		}
}
//nutWasherM3();

module washerNutM3 () {
	translate([0., 0.,0.5]) 
		rotate([180., 0, 0]) 
			union() {
				ISO4032("M3", part_mode="default");
				ISO7089("M3", part_mode="default");
			}
}
//washerNutM3();

module tigePiedM3 () {
		translate([0,0,57]) washerNutM3();
		translate([0,0,27]) nutWasherM3();
		translate([0,0,3+10+6]) washerNutM3();
		translate([0,0,9+3]) nutWasherM3();
		cylinder(h=60,r=3.1/2, center = false);
	
}

module tigeMotorM3 () {
		translate([0,0,3+10]) washerNutM3();
		translate([0,0,3+3]) nutWasherM3();
		translate([0,0,-10]) cylinder(h=30,r=3.1/2, center = false);
}

module motor () {
	stepper_motor_mount(17);
	translate([-14,-14,-50]) tigeMotorM3();
	translate([-14,14,-50]) tigeMotorM3();
	translate([14,-14,-50]) tigeMotorM3();
	translate([14,14,-50]) tigeMotorM3();
}

module gears () {
	rotate(360./100) gear(
		number_of_teeth=50,
		circular_pitch=600, 
		pressure_angle=28,
		gear_thickness=10,
		rim_thickness=10,
		bore_diameter=6
	);

	D = 83.3333 + 16.6667;
	translate([D,0,0]) gear(
		number_of_teeth=10,
		circular_pitch=600, 
		pressure_angle=28,
		gear_thickness=10,
		rim_thickness=10,
		bore_diameter=5);
	
	translate([D,0,-10]) motor();	
}
//color([1,1,0]) gears();
 
module gearAxis () {
	translate([0,0,-19.5]) union() {
		translate([0,0,10]) washerNutM8(); 
		translate([0,0,-12]) nutWasherM8();
		translate([0,0,10-7]) bearing(608);
		translate([0,0,10-7-7-0.2]) bearing(608);
		translate([0,0,-13]) cylinder(h=50,r=4);
		translate([0,0,17.9+0.74]) 
			difference() {
				cylinder(h=1.48,r=15, center = true);
				cylinder(h=1.48,r=4.2, center = true);
			}
		translate([0,0,17.9+0.74+10]) washerNutM8(); 
	}
}
gearAxis();

module pied () {
translate([0,0,-19]) union() { 
	difference() {
		union() {
			translate([0,0,5]) difference() {
				cube(size = [40,40,10], center = true);
				cylinder(h=10,r=10.5, center = true);
  			}
			translate([0,0,-5]) difference() {
				cube(size = [40,40,10], center = true);
				cylinder(h=10,r=10.5, center = true);
  			}
			translate([0,0,-15]) difference() {
				cube(size = [40,40,10], center = true);
				cylinder(h=10,r=10.5, center = true);
  			}
		}
		union() {
			translate([-14,-14,-20]) cylinder(h=30,r=3.1/2, center = false);
			translate([-14,14,-20]) cylinder(h=30,r=3.1/2, center = false);
			translate([14,-14,-20]) cylinder(h=30,r=3.1/2, center = false);
			translate([14,14,-20]) cylinder(h=30,r=3.1/2, center = false);
		}
	}
	translate([0,0,0])
	union () {
		translate([-14,-14,-17-30]) tigePiedM3();
		translate([-14,14,-17-30]) tigePiedM3();
		translate([14,-14,-17-30]) tigePiedM3();
		translate([14,14,-17-30]) tigePiedM3();
	}
}
}
// pied();


module plateau () {
translate ([0,0,10])
	difference () {
		cylinder(h=10,r=90);
		cylinder(h=9,r=6);
  	}
}
// plateau();

module plaque () {

translate ([-110,-100,-57]) 
difference () {
cube([250,200,10]);
//translate([-14,-14,-50]) cylinder(h=3,r=4.5);
	//translate([-14,14,-50]) tigeMotorM3();
	//translate([14,-14,-50]) ;
//	translate([14,14,-50])
}
}
// plaque();
//cube([250,200,10],center=true);


module model () {
color([1,1,0]) gears();
color([0,1,0]) plateau();
pied();
%plaque(); 
}
$fn=100;
model();

module eclate () {
translate ([0,0,100]) color([1,1,0]) gears();
translate ([0,0,10]) color([0,1,0]) plateau();
translate([0,0,0]) pied();
}
//eclate();

//translate ([-110,-100,-70]) cube([250,200,15]);
//translate ([-110,-100,-15]) cube([250,200,10]);

//translate ([-110,-100,-15]) cube([15,200,30]);