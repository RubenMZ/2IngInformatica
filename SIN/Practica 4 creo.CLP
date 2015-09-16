(deffacts constructor
"mi constructor"
(datos 1 2 4)
(datos 3 5 2 3)
(datos 2 4 7 8 2)
(datos rojo 3 4)
)

(deffacts constructor2
(datos 1 2 4 3 2)
(datos 4 8 3 8)
(datos 3 6 6)
(datos 1 3 4 1)
)

(defrule reglaComprobar
(datos ?x&:(numberp ?x)
?y&:(= (* 2 ?x) ?y)
$?z
?y)
=>
(printout t "La regla para comprobar, x=" ?x " y= " ?y " y comodin: " $?z crlf)
)

(defrule reglaVariables
"probando operador :"
(datos ?x&:(numberp ?x)
?y&:(> ?y ?x)
$?z
?x)
=>
(printout t "Se dispara mi regla, x=" ?x " y= " ?y " y comodin: " $?z crlf)
)

(defrule reglaOrdenar
"para comprobar hechos ordenados"
(datos $?x
?y&:(numberp ?y)
?z&:(> ?y ?z)
$?t
)
=>
(printout t "No esta ordenado, x=" $?x " y= " ?y " z= " ?z " t= " $?t crlf)
)

(defrule noOrdenadoDeMenorAMayor
"regla para buscar vectores no ordenados, ya que busca dos numeros que nos esten ordenados pero no recorre el vector"
(vector ?nombre
$?cabeza
?x&:(numberp ?x)
?y&:(numberp ?y)&:(> ?x ?y)
$?cola)
=>
(printout t "El vector " ?nombre " no está ordenado de menor a mayor" crlf)
)

(deffacts hechos 
	(vector v1 2 6 1 verde 6 "pepe" 8 3 4 9)
	(vector v2 1 2 3 4 5 6 7)
	(vector v3 8 1 "tres" 3 9 3.4 2 4 adios 4))

(defrule ordenaDeMenorAMayor
"regla para buscar vectores no ordenados, ya que busca dos numeros que nos esten ordenados pero no recorre el vector"
?h<-(vector ?nombre
$?cabeza
?x&:(numberp ?x)
?y&:(numberp ?y)&:(> ?x ?y)
$?cola)
=>
(retract ?h)
(assert (vector ?nombre $?cabeza ?y ?x $?cola))
(printout t "El vector " ?nombre " no está ordenado de menor a mayor" crlf)
)

(defrule eliminarNoNumerico
	;detectar elemento no numerico
	?h<-(vector ?nombre 
	$?cabeza
	?x&~:(numberp ?x)
	$?cola)
	=>
	;eliminar el hecho no numerico
	(retract ?h)
	(printout t "Borrado " ?nombre crlf)
	;afirmar el hecho sin el elemnto numerico
	(assert(vector ?nombre $?cabeza $?cola))
	)

(deffacts hechos
	(dato 3)
	(dato 1)(dato 7)(dato 2)
	(todos-los-datos)
	)

(defrule imprimeOrdenado
	?h<-(dato ?valor)
	(not(dato ?y&:(<?y ?valor)))
	=>
	(retract ?h)
	(printout t ?valor crlf))
)


(defrule insertaOrdenado
	;Seleccionar un hecho dato y el hecho todos-los-datos
	(dato ?valor&:(numberp ?valor))
	;Seleccionar todos-los-datos
	?h<-(todos-los-datos $?valores)
	;No existe un valor más pequeño que no este en todos-los-datos
	(not (and 
		(dato ?y&:(< ?y ?valor))
		(not (todos-los-datos $?cabeza ?y $?cola))
		))

		;el valor no está en todos-los datos
		(not (todos-los-datos $?cabeza ?valor $?cola))
	=>
	;insertar el dato en todos-los-datos
	(retract ?h)
	(assert(todos-los-datos $?valores ?valor))
	
)

(defrule regla
	;Regla que imprime "dia salvado" si existe un héroe desocupado, se activa tantas veces como hechos cumplan el patron
	(objetivo salvar-el-dia)
	(heroe (estado desocupado)
	=>
	(printout t "dia salvado" crlf)
)

(defrule regla
	;Regla que imprime "dia salvado" si existe un héroe desocupado, se activa solo una vez aunque existan varios hechos que la cumplan
	(objetivo salvar-el-dia)
	(exists (heroe (estado desocupado))
	=>
	(printout t "dia salvado" crlf)
)


(deffacts hechos
	(dato 1)
	(dato 2)
	(dato 4)
	(dato 7)
	(auxDato 7)
	(auxDato 4)
	)

(defrule copiaDato
	(dato ?x)
	(not(auxDato ?x))
	=>
	(assert(auxDato ?x))
)

(defrule informarTodosCopiados
	;Se activa la regla para cada dato e imprime por cada dato
	(dato ?x)
	(auxDato ?x)
	=>
	(printout t "Copia terminada" crlf)

)

(defrule informarTodosCopiados
	;Se activa la regla cuando todos los datos se han copiado e imprime una sola vez
	(forall (dato ?x)
	(auxDato ?x))
	=>
	(printout t "Copia terminada" crlf)

)