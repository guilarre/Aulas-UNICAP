'use client';
import { useState, useEffect } from 'react';
import axios from 'axios';
export default function Home() {
 const [produtos, setProdutos] = useState([]);
 const [loading, setLoading] = useState(true);
 const [erro, setErro] = useState(null);
 useEffect(() => {
 axios.get(
 `${process.env.NEXT_PUBLIC_BACK4APP_URL}/classes/Produto`,
 {
 headers: {
 'X-Parse-Application-Id': process.env.NEXT_PUBLIC_BACK4APP_APP_ID,
 'X-Parse-REST-API-Key': process.env.NEXT_PUBLIC_BACK4APP_API_KEY,
 },
 }
 )
 .then((resposta) => {
 setProdutos(resposta.data.results);
 setLoading(false);
 })
 .catch((err) => {
 setErro(err.message);
 setLoading(false);
 });
 }, []); // [] = executa só uma vez, quando o componente carrega
 if (loading) return <p>Carregando...</p>;
 if (erro) return <p>Erro: {erro}</p>;
 return (
 <main style={{ maxWidth: 600, margin: '40px auto', padding: 24 }}>
 <h1>Produtos</h1>
 {produtos.map((produto) => (
 <div key={produto.objectId}>
 <h3>{produto.nome}</h3>
 <p>R$ {produto.preco.toFixed(2)}</p>
 <p>Categoria: {produto.categoria}</p>
 </div>
 ))}
 </main>
 );
}

// import Image from "next/image";
// import styles from "./page.module.css";
//
// export default function Home() {
//   return (
//     <div className={styles.page}>
//       <main className={styles.main}>
//         <Image
//           className={styles.logo}
//           src="/next.svg"
//           alt="Next.js logo"
//           width={100}
//           height={20}
//           priority
//         />
//         <div className={styles.intro}>
//           <h1>
//             To get started, edit the{" "}
//             <code className={styles.code}>page.js</code> file.
//           </h1>
//           <p>
//             Looking for a starting point or more instructions? Head over to{" "}
//             <a
//               href="https://vercel.com/templates?framework=next.js&utm_source=create-next-app&utm_medium=appdir-template-tw&utm_campaign=create-next-app"
//               target="_blank"
//               rel="noopener noreferrer"
//             >
//               Templates
//             </a>{" "}
//             or the{" "}
//             <a
//               href="https://nextjs.org/learn?utm_source=create-next-app&utm_medium=appdir-template-tw&utm_campaign=create-next-app"
//               target="_blank"
//               rel="noopener noreferrer"
//             >
//               Learning
//             </a>{" "}
//             center.
//           </p>
//         </div>
//         <div className={styles.ctas}>
//           <a
//             className={styles.primary}
//             href="https://vercel.com/new?utm_source=create-next-app&utm_medium=appdir-template&utm_campaign=create-next-app"
//             target="_blank"
//             rel="noopener noreferrer"
//           >
//             <Image
//               className={styles.logo}
//               src="/vercel.svg"
//               alt="Vercel logomark"
//               width={16}
//               height={14}
//             />
//             Deploy Now
//           </a>
//           <a
//             className={styles.secondary}
//             href="https://nextjs.org/docs?utm_source=create-next-app&utm_medium=appdir-template&utm_campaign=create-next-app"
//             target="_blank"
//             rel="noopener noreferrer"
//           >
//             Documentation
//           </a>
//         </div>
//       </main>
//     </div>
//   );
// }
