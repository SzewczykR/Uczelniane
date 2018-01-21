<?php

namespace Scheduler\Models;

class Language extends SemesterClass {

	public function getFormName(): string {
		return "Język";
	}
	
	public function getColor () :string {
		return "Red";
	}

}