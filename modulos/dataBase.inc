<?php

require_once('constants.inc');

abstract class DataBase {

	private static $dbHost = DB_HOST;
	private static $dbUser = DB_USER;
	private static $dbPass = DB_PASS;
	
	protected $dbName = DB_NAME;
	protected $query;
	protected $rows = array();
	private $conn;
	public $message = 'OK';

	abstract protected function get();
	abstract protected function set();
	abstract protected function edit();
	abstract protected function delete();

	private function openConnection(){
		$this->conn = new mysqli(self::$dbHost, self::$dbUser, self::$dbPass, $this->dbName);
		$this->conn->set_charset("utf8");
		if (mysqli_connect_errno($this->conn)) {
  			echo "Failed to connect to MySQL: " . mysqli_connect_error();
		}

	}

	private function closeConnection(){
		$this->conn->close();
	}

	protected function executeSingleQuery(){
		
			$this->openConnection();
			$this->conn->query($this->query);
			$this->closeConnection();
	}

	protected function getResultFromQuery(){
		$this->openConnection();
		$result = $this->conn->query($this->query);

		if (!$result) {
  			throw new Exception($this->conn->error, 1);
		}
		while ($this->rows[] = $result->fetch_assoc());
		$result->close();
		$this->closeConnection();
		array_pop($this->rows);
	}

}

?>