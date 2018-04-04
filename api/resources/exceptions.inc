<?php

class NotFoundException extends Exception{
	public $error;
	public $code;
	public $message;

	public function __construct($message){
		$this->code = 404;
		$this->error = "not_found";
		$this->message = $message;
		parent::__construct($this->message, $this->code);
	}
}

class BadRequestException extends Exception{
	public $error;
	public $code;
	public $message;

	public function __construct($message){
		$this->code = 400;
		$this->error = "bad_request";
		$this->message = $message;
		parent::__construct($this->message, $this->code);
	}
}

class ConflictException extends Exception{
	public $error;
	public $code;
	public $message;

	public function __construct($message){
		$this->code = 409;
		$this->error = "conflict";
		$this->message = $message;
		parent::__construct($this->message, $this->code);
	}
}

?>