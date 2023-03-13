# Save directory structure
cwd="$(pwd)"
root="$(git rev-parse --show-toplevel)"
build="$root/build"

# Build all the files
cmake -S $root -B $build
cd $build
make

# Move compile_commands.json to a place where ccls can see it
if [[ -e "$build/compile_commands.json" ]]; then
  mv $build/compile_commands.json $root
else
  echo -e "\e[31mCould not find compile_commands.json\e[0m"
fi

# Restore originally working directory
cd $cwd
