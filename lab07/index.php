<?php

require "./vendor/autoload.php";

use Scheduler\Models\Lecture;
use Scheduler\Models\Schedule;
use Scheduler\Models\Laboratory;
use Scheduler\Models\Exercise;
use Scheduler\Models\Language;
use Scheduler\Models\WF;
use Scheduler\Models\event_1;
use Scheduler\Models\event_2;

$twig = new Twig_Environment(new Twig_Loader_Filesystem("/"), []);

$schedule = new Schedule();


// poniedziałek
$schedule->save(new Lecture("Bazy danych", "Aleksander Kłosow", "C212"), 1, 1);
$schedule->save(new Lecture("Projektowanie i programowanie obiektowe", "Aleksander Kłosow", "C212"),1,2);
$schedule->save(new Language("Język angielski", "Magdalena Adreli", "C311"),1,3);
$schedule->save(new Lecture ("Sieci komputerowe", "Piotr Nadybski", "C212"),1,4);
$schedule->save(new Laboratory("Sieci komputerowe", "Piotr Nadybski", "C11"),1,5);

//wtorek
$schedule->save(new Lecture ("Podstawy teorii informacji", "Arkadiusz Grzybowski", "C212"),2,3);
$schedule->save(new Lecture ("Podstawy teorii informacji", "Arkadiusz Grzybowski", "C212"),2,4);
$schedule->save(new Laboratory("Projektowanie i programowanie obiektowe", "Krzysztof Rewak", "A241"),2,5);
$schedule->save(new Laboratory("Projektowanie i programowanie obiektowe", "Krzysztof Rewak", "A241"),2,6);

// środa
$schedule->save(new Lecture("Podstawy metod probabilistycznych i statystyki", "Karol Selwat", "C212"),3,1);
$schedule->save(new Laboratory("Architektura komputerów", "Jan Duda", "D16"),3,2);
$schedule->save(new Exercise("Podstawy metod probabilistycznych i statystyki", "Karol Selwat", "C222"),3,3);
$schedule->save(new Laboratory("Bazy danych", "Józefa Górska-Zając", "A218"),3,4);

//czwartek
$schedule->save(new Lecture("Architektura komputerów", "Wojciech Kordecki", "C212"),4,5);

//piątek

//null


echo $twig->render("index.twig", [
    "schedule" => $schedule,
]);
