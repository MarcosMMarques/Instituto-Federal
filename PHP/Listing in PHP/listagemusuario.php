<!DOCTYPE html>
<html lang="pt-BR">
	<head>
		<meta charset="utf-8">
		<title>Listagem de Usuario</title>
		<link rel="stylesheet" href="style.css">
	</head>
	
	<body>
	
		<h1>Listagem de Usuário</h1>
		
		<?php
			require_once 'rb-mysql.php';
			
			R::setup('mysql:host=localhost;dbname=webdev', 'root', '');
			
			$usuario = R::dispense('usuario');
			
			if(isset($_POST['nome']) && ($_POST['email'])  && ($_POST['senha'])) {
					
					
				$usuario->Nome = $_POST['nome'];
				$usuario->Email = $_POST['email'];
				$usuario->Senha = $_POST['senha'];			
				R::store($usuario);
			}
			
			$usuario = R::findALL('usuario');
			echo '<table>'
				. '<thead>'
				. 	'<tr>'
				. 		'<th>Id</th>'
				. 		'<th>Nome</th>'
				. 		'<th>Email</th>'
				. 		'<th>Senha</th>'
				. 	'</tr>'
				. '</thead>'
				. '<tbody>';
				
			foreach($usuario as $e){
				echo "<tr>"
					. "<td>{$e->id}</td>"
					. "<td>{$e->Nome}</td>"
					. "<td>{$e->Email}</td>"
					. "<td>{$e->Senha}</td>"
					. "</tr>";
			}
			
			echo '</tbody>'
				 . '</table>';
				 
			R::close();
		?>
	</body>
</html>