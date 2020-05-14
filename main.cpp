#include"CompleteReg.h"
#include <iostream>
int main() {
	CompleteReg reg;
	reg.addTeam("fner", "sl", 1907);
	reg.addTeam("barca", "mor", 1868);
	reg.displayAllTeams();
	reg.removeTeam("barca");
	reg.removeTeam("FnEr");
	reg.displayAllTeams();
	reg.addTeam("fner", "sl", 1907);
	reg.addTeam("barca", "mor", 1868);
	reg.addPlayer("barca", "messi", "rw");
	reg.addPlayer("barca", "dembele", "rw");
	reg.addPlayer("baRCA", "griezman", "lw");
	reg.addPlayer("fner", "griezman", "gk");
	reg.displayTeam("barca");
	reg.displayTeam("FNER");
	reg.displayPlayer("GRiezman");
	reg[0].displayPlayer("griezman");
	CompleteReg reg2 = reg;
	CompleteReg reg3 = CompleteReg(reg);
	reg2.displayAllTeams();
	reg3.displayAllTeams();
	reg3.addPlayer("fner", "apyah", "cm");
	reg3.displayAllTeams();
}