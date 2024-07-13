using System.Diagnostics;
using GeneticSharp.Domain.Chromosomes;
using GeneticSharp.Domain.Mutations;
using GeneticSharp.Domain.Randomizations;
using GeneticSharp.Runner.UnityApp.Car;

public class Mutation : IMutation
{
    public bool IsOrdered { get; private set; } // indicating whether the operator is ordered (if can keep the chromosome order).

    public Mutation()
    {
        IsOrdered = true;
    }

    public void Mutate(IChromosome chromosome, float probability)
    {

        // Generate a new chromosome
        CarChromosome newChromosome = new CarChromosome(((CarChromosome)chromosome).getConfig());

        for (int i = 0; i < chromosome.Length; i++)
        {
            if (RandomizationProvider.Current.GetDouble() <= probability)
            {
                // Get a random gene from the new chromosome
                int geneIndex = RandomizationProvider.Current.GetInt(0, newChromosome.Length);

                // Replace the gene value in the chromosome
                chromosome.ReplaceGene(i, newChromosome.GetGene(geneIndex));
            }
        }
    }

}
