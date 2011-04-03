import System(getArgs)
import Data.Maybe(fromJust, isJust)
import qualified Language.Cpp.Clang.FFI as Clang

test args = do
  -- args <- getArgs
  index <- Clang.createIndex False False
  mtu <- Clang.parseTranslationUnit index Nothing args [] Clang.TranslationUnit_None
  let tu = if isJust mtu then fromJust mtu else error "No TXUnit!"
  defDisplayOpts <- Clang.defaultDiagnosticDisplayOptions
  let printDiag i = do
         diag <- Clang.getDiagnostic tu i
         clstr <- Clang.formatDiagnostic diag defDisplayOpts
         str <- Clang.getCString clstr
         putStrLn str
         Clang.disposeString clstr
  numDiags <- Clang.getNumDiagnostics tu
  putStrLn $ "numDiags:" ++ show numDiags
  mapM_ printDiag [0..numDiags]
  Clang.disposeTranslationUnit tu
  Clang.disposeIndex index
  putStrLn "hehe"