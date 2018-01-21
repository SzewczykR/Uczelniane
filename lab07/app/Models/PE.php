<?php

namespace Scheduler\Models;

class WF extends SemesterClass {

	public function getFormName(): string {
		return "WF";
	}
	
	public function getColor() : string {
		return "pink";
	}	

}