<html>
  <link  href="style.css" rel="stylesheet" type="text/css"/>
  <head>
    <title>Conteudo</title>
  </head>
  <body>
 <header>
        </header>

        <main>
          <table>
            <thead>
              <tr>
                <th>Conteudo</th>
              </tr>
            </thead>
            <tbody>
            <?php 
    $paginas['https://google.com'] = 'Google';
    $paginas['https://www.americanas.com.br/'] = 'Americanas';
    $paginas['https://www.casasbahia.com.br'] = 'Casas Bahia';
            foreach($paginas as $link => $titulo){
              echo "<tr><td><a href=\"$link\">$titulo</a></td></tr>";
            }
            ?>
</tbody>
          </table>












          
<!--             <table>
                <thead>
                    <tr>
                        <th>
                            Sigla
                        </th>
                        <th>
                            Nome
                        </th>
                    </tr>
                </thead>
                <tbody> 
          
                    <?php 
                        foreach($estados as $sigla => $nome){
                                echo "<tr>
                                        <td>
                                            $sigla
                                        </td>
                                        <td>
                                            $nome
                                        </td>
                                    </tr>";
                            }
                    ?>
                </tbody>
            </table> -->
        </main>
        
        <footer>
        </footer> 
  </body>
</html>