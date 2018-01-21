<?php

namespace Scheduler\Models;

class exercise extends SemesterClass {

	public function getFormName(): string {
		return "Ćwiczenia";
	}
	
	public function getColor() : string {
		return  "purple";
	}	

}